/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:35:31 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/06 21:45:57 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 * This function calculates the memory position of the pixel located in (x,y)
 * and stores the color value on that memory spot. Is beter that mlx_pixel_put()
 * because we can calculate the whole image and then push it to the window, 
 * comparing to mlx_pixel_put() that renders pixel by pixel.
*/
static void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	fractal_check(t_fractal *fractal, t_complex *z, t_complex *c)
{
	if (!ft_strncmp(fractal->name, "Julia", 5))
	{
		z->x = c->x;
		z->y = c->y;
		c->x = fractal->julia.x;
		c->y = fractal->julia.y;
	}
	else
	{
		z->x = 0.0;
		z->y = 0.0;
	}
}

/*
 *	 (0,0)--------(W,0)					(-2,2)---------(2 , 2)
 *		|			|	rescale_double()	|			|
 * 		|			|  ==================>	|			|
 * 		|			|						|			|
 * 	  (0,H)______(W, H)					(-2,-2)________(2, -2)
 * 
 * 		MANDELBROT
 * 		z = z² + c
 * 		z0 = (0, 0)
 * 		c is the actual point
*/
static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	c.x = rescale_double(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
	c.y = rescale_double(y, -2, 2, HEIGHT) * fractal->zoom + fractal->shift_y;
	fractal_check(fractal, &z, &c);
	i = 0;
	while (i < fractal->n_iterations)
	{
		if (!ft_strncmp(fractal->name, "Bonus", 5))
			z = add_complex(cubic_complex(z), c);
		else
			z = add_complex(square_complex(z), c);
		if (complex_modulus(z) > fractal->escape_value)
		{
			color = rescale_double(i, BLACK, WHITE, fractal->n_iterations);
			my_pixel_put(&(fractal->img_data), x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&(fractal->img_data), x, y, WHITE);
}

/*
 * This function renders the fractal image:
 *  	1) calcules the color of each pixel of the image
 * 			with pixel_handler().
 * 		2) Then pushes the image to the window.
*/
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->img_data.img, 0, 0);
}
