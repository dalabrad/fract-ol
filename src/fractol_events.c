/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:18:03 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/05 10:38:36 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	key_handler(int keysym, t_fractal *fractal)
{
	ft_printf("%s set:\n", fractal->name);
	ft_printf("The key '%d' has been pressed.\n", keysym);
	return (0);
}
