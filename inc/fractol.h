/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:43:22 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/04 10:43:48 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define INPUT_ERROR 1
# define MLX_ERROR 2
# define MALLOC_ERROR 3

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/*
 *	FRACTAL STRUCT:
 *	~ MLX pointers (mlx_init() and window)
 *	~ Image
 *	~ Hooks values
*/
typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	t_img	img_data;
	//Hooks member variables
}	t_fractal;

//	fractol_error_msg.c
void	error_msg(int err_id);

#endif