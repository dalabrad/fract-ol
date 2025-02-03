/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:49:17 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/03 16:05:09 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fract-ol.h"

int	main(int argc ,char *argv[])
{
	if ((argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 11)) ||
			(argc == 4 && !ft_strncmp(argv[1], "Julia", 6)))
		ft_printf("Everything ok!!\n");
	else
	{
		ft_printf("Error! Please enter:\n./fractol mandelbrot\nor\n./fractol julia <real part> <imaginary part>\n");
		return (1);
	}
	return (0);
}
