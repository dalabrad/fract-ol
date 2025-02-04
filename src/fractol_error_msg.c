/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:48:22 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/04 09:59:15 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	error_msg(int err_id)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	if (err_id == INPUT_ERROR)
	{
		ft_putstr_fd("Please enter:\n\t'./fractol Mandelbrot' or\n", 2);
		ft_putstr_fd("\t'./fractol Julia <real part> <imaginary part>'\n", 2);
	}
}
