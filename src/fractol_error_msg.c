/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:48:22 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/06 11:30:08 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 * This function prints an error msg on STDERR_FLENO given the err_id.
 * it returns the err_id too so it can be used inside a return() or exit().
 */
int	error_msg(int err_id)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	if (err_id == INPUT_ERROR)
	{
		ft_putstr_fd("Please enter:\n\t'./fractol Mandelbrot' or\n", 2);
		ft_putstr_fd("\t'./fractol Julia <real part> <imaginary part>'\n", 2);
	}
	else if (err_id == MLX_ERROR)
		ft_putstr_fd("The connection to mlx server failed.\n", 2);
	else if (err_id == WINDOW_ERROR)
		ft_putstr_fd("Unable to open new window.\n", 2);
	else if (err_id == IMG_ERROR)
		ft_putstr_fd("Unable to create new image.\n", 2);
	else if (err_id == JULIA_ARG_ERROR)
	{
		ft_putstr_fd("Bad Julia argument format.\n", 2);
		ft_putstr_fd("Correct format : '(-)21678.900'.\nOnly use number", 2);
		ft_putstr_fd(" characters, a minus sign if the argument is nega", 2);
		ft_putstr_fd("tive and separate the decimal part with a dot (.).\n", 2);
	}
	return (err_id);
}
