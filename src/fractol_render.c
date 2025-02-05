/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:35:31 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/05 11:28:46 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
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

	z.x = 0.0;
	z.y = 0.0;
	c.x = rescale_double(x, -2, 2, WIDTH) + fractal->shift_x;
	c.y = rescale_double(y, -2, 2, HEIGHT) + fractal->shift_y;
	i = 0;
	while (i < fractal->n_iterations)
	{
		z = add_complex(square_complex(z), c);
		if (complex_modulus(z) > fractal->escape_value)
		{
			color = rescale_double(i, BLACK, WHITE, fractal->n_iterations);
			my_pixel_put(&(fractal->img_data), x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&(fractal->img_data), x, y, BLACK);
}

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
