/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:49:17 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/06 11:27:08 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

/*
 * This function checks that the argument has the right format:AnyPropertyType
 * 		1) only one minuns sign for negative values
 * 		2) checks that doesn't start on a dot (.)
 * 		3) checks that there's only number characters and one dot (.)
 * 		4) checks that the last character is not a dot.
*/
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

/*
 * This function transforms a string that has the right format (checked by 
 * check_argument()) and transforms it returning a double.
 */
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

/*
 * This function checks the format first:
 *		~ If it is not correct prints error msg and exits the program
 *		~ If format correct trasnforms the string to double with atod()
 */
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
