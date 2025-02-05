/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:12:12 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/05 18:33:58 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 * Rescales the value unscaled_n contained in [0, old_max] to [new_min, new_max]
*/
double	rescale_double(double unscaled_n, double new_min, double new_max,
			double old_max)
{
	return ((new_max - new_min) * unscaled_n / old_max + new_min);
}

t_complex	add_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = pow(z.x, 2) - pow(z.y, 2);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_complex	cubic_complex(t_complex z)
{
	t_complex	result;

	result.x = pow(z.x, 3) - 3 * pow(z.y, 2) * z.x;
	result.y = 3 * pow(z.x, 2) * z.y - pow(z.y, 3);
	return (result);
}

double	complex_modulus(t_complex z)
{
	return (sqrt(pow(z.x, 2) + pow(z.y, 2)));
}
