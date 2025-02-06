/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:49:17 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/06 11:14:47 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

static int	check_argument(char *str)
{
	int	dot_count;

	if (*str == '-')
		str++;
	if (*str == '.')
		return (0);
	dot_count = 0;
	while (*str)
	{
		if (((*str < '0' || *str > '9') && *str != '.' )
			|| (*str == '.' && dot_count == 1))
			return (0);
		else if (*str == '.' && !*(str + 1))
			return (0);
		else if (*str == '.' && dot_count == 0)
			dot_count = 1;
		str++;
	}
	return (1);
}

static double	atod(char *str)
{
	double	result;
	int		sign;
	int		i;

	sign = 1;
	result = 0.0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	i = 1;
	while (*str)
	{
		result += (*str - '0') / pow(10.0, (double)i++);
		str++;
	}
	return (sign * result);
}

static double	get_julia_arg(char *str)
{
	if (!check_argument(str))
	{
		error_msg(JULIA_ARG_ERROR);
		exit (JULIA_ARG_ERROR);
	}
	return (atod(str));
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 11))
		|| (argc == 4 && !ft_strncmp(argv[1], "Julia", 6)))
	{
		fractal.name = argv[1];
		if (argc == 4)
		{
			fractal.julia.x = get_julia_arg(argv[2]);
			fractal.julia.y = get_julia_arg(argv[3]);
			printf("Julia real part = %f\n", fractal.julia.x);
			printf("Julia imaginary part = %f\n", fractal.julia.y);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
	}
	else
	{
		error_msg(INPUT_ERROR);
		return (EXIT_FAILURE);
	}
	mlx_loop(fractal.mlx);
	return (EXIT_SUCCESS);
}
