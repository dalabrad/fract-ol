/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractal_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:16:13 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/04 11:58:54 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
}
