/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractal_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:16:13 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/06 12:07:12 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 * This function innitializes the hook member values for the fractal:
 * 	 ~ escape_value is the value which is max module value for a point to escape
 * 	 ~ n_iterations is tied to the resolution of image (more iterations more res)
 * 		will change when pressing + or - keys.
 * 	 ~ shift_(x/y) will estore the movement of the image (useful to move image 
 * 		with arrow keys). Starts on 0 because we want the image centered.
 *	 ~ zoom will store the zoom data, will vary when moving the mouse wheel. 
 		Starts in 1 then will increase and decrease exponentially.
 */
static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 2;
	fractal->n_iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

/*
 * This function innitializes the mlx_hooks:
 * 	 1) Key_hoop to send the pressed keys to key_handler()
 * 	 2) A hook to call close_handler() when window close button (x) is pressed.
 * 	 3) Mouse_hook to send the pressed mouse button and its location to 
 * 		mouse_handler()
 */
static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->window, KeyPress, KeyPressMask,
		key_handler, fractal);
	mlx_hook(fractal->window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
	mlx_hook(fractal->window, ButtonPress, ButtonPressMask,
		mouse_handler, fractal);
}

/*
 * First, this function innitializes all the necesary things for minilibx :
 * 	 1) Connects with mlx server.
 * 	 2) Creates new window.
 * 	 3) Creates new image.
 *------If any of this steps fails allocating memory a clean exit is performed.
 *   4) Get image pixel address.
 * Then starts the data and the event hooks:
 *	 5) Call data_init().
 *	 6) Call events_init().
 	
 */
void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit (error_msg(MLX_ERROR));
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->window)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit (error_msg(WINDOW_ERROR));
	}
	fractal->img_data.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img_data.img)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit (error_msg(IMG_ERROR));
	}
	fractal->img_data.addr = mlx_get_data_addr(fractal->img_data.img,
			&(fractal->img_data.bpp), &(fractal->img_data.line_len),
			&(fractal->img_data.endian));
	data_init(fractal);
	events_init(fractal);
}
