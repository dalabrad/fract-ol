/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:18:03 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/05 13:13:58 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img_data.img);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_plus)
	{
		fractal->n_iterations += 10;
		ft_printf("Interations raised to : %d\n", fractal->n_iterations);
	}
	else if (keysym == XK_minus)
	{
		if (fractal->n_iterations > 10)
			fractal->n_iterations -= 10;
		else if (fractal->n_iterations <= 10 && fractal->n_iterations > 1)
			fractal->n_iterations -= 1;
		ft_printf("Interations decreased to : %d\n", fractal->n_iterations);
	}
	else if (keysym == XK_Left)
		fractal->shift_x += 0.1 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.1 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y += 0.1 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y -= 0.1 * fractal->zoom;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 1.20;
	else if (button == Button4)
		fractal->zoom *= 0.80;
	fractal_render(fractal);
	return (x + y);
}
