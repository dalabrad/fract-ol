/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtest_color_changing_window.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:07:42 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/03 14:42:27 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define MLX_ERROR 1
#define MALLOC_ERROR 2
#define WIDTH 1920
#define HEIGHT 1080

typedef	struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef	struct s_mlx
{
	void	*mlx;
	void	*window;
	t_img	img;
}	t_mlx;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	color_screen(t_mlx *data, int color)
{
	int i;
	int	j;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
				my_mlx_pixel_put(&(data->img), i, j, color);
			i++;
		}
		j++;
	}		
}

int	f(int keysym, t_mlx *data)
{
	printf ("Key %d pressed.\n", keysym);
	if (keysym == XK_r)
	{
		color_screen(data, 0xff0000);
	}
	else if (keysym == XK_g)
	{
		color_screen(data, 0xff00);
	}
	else if (keysym == XK_b)
	{
		color_screen(data, 0xff);
	}
	else if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_display(data->mlx);
		free (data->mlx);
		exit(1);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_ptr, 0, 0);
	return(0);
}

int	main(void)
{
	t_mlx data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return(MLX_ERROR);
	data.window = mlx_new_window(data.mlx, WIDTH, HEIGHT, "My window");
	if (!data.window)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return(MLX_ERROR);
	}
	data.img.img_ptr = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.address = mlx_get_data_addr(data.img.img_ptr, &(data.img.bpp), &(data.img.line_len), &(data.img.endian));
/* 	printf("Line_len : %d <---> WIDTH : %d\n", data.img.line_len, WIDTH);
	printf("Bpp : %d\n", data.img.bpp);
	printf("Endian : %d\n",data.img.endian); */
	mlx_key_hook(data.window, f, &data);
	mlx_loop(data.mlx);
}
