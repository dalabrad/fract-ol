/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:49:17 by dalabrad          #+#    #+#             */
/*   Updated: 2024/10/08 11:46:08 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "libft/libft.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	printf("ft_strlen('Hola!) = %ld\n", ft_strlen("Hola!"));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}

