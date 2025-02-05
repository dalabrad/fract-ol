/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractal_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:16:13 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/05 12:13:14 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 2;
	fractal->n_iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->window, key_handler, fractal);
	mlx_hook(fractal->window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

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
