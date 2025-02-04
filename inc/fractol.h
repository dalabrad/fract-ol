/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:43:22 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/04 18:45:12 by dalabrad         ###   ########.fr       */
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
# define WINDOW_ERROR 3
# define IMG_ERROR 4

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

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
	char	*name;
	void	*mlx;
	void	*window;
	t_img	img_data;
	//Hooks member variables
}	t_fractal;

//	fractol_error_msg.c
int			error_msg(int err_id);

//	fractol_fractal_init.c
void		fractal_init(t_fractal *fractal);

//	fractol_math_utils.c
double		rescale_double(double unscaled_n, double new_min, double new_max,
				double old_max);
t_complex	add_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif