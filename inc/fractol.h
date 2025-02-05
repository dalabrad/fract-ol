/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:43:22 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/05 12:10:39 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include <X11/X.h>
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

// Colors
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red

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
	double	escape_value;
	int		n_iterations;
	double	shift_x;
	double	shift_y;
}	t_fractal;

//	fractol_error_msg.c
int			error_msg(int err_id);

//	fractol_fractal_init.c
void		fractal_init(t_fractal *fractal);

//	fractol_events.c
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);

//	fractol_math_utils.c
double		rescale_double(double unscaled_n, double new_min, double new_max,
				double old_max);
t_complex	add_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		complex_modulus(t_complex z);

//	fractol_render.c
void		fractal_render(t_fractal *fractal);
#endif