/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:48:22 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/04 11:56:17 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	error_msg(int err_id)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	if (err_id == INPUT_ERROR)
	{
		ft_putstr_fd("Please enter:\n\t'./fractol Mandelbrot' or\n", 2);
		ft_putstr_fd("\t'./fractol Julia <real part> <imaginary part>'\n", 2);
	}
	else if (err_id == MLX_ERROR)
		ft_putstr_fd("the connection to mlx server failed.\n", 2);
	else if (err_id == WINDOW_ERROR)
		ft_putstr_fd("unable to open new window.\n", 2);
	else if (err_id == IMG_ERROR)
		ft_putstr_fd("unable to create new image.\n", 2);
	return (err_id);
}
