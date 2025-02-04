/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:49:17 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/04 10:10:14 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

int	main(int argc, char *argv[])
{
	if ((argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 11))
		|| (argc == 4 && !ft_strncmp(argv[1], "Julia", 6)))
		ft_printf("Everything ok!!\n");
	else
	{
		error_msg(INPUT_ERROR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
