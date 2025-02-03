/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:49:17 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/03 10:12:13 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define MLX_ERROR 1
#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img_data_ptr;
}	t_mlx_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img_data_ptr->img);
		free(data->img_data_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free (data->mlx_ptr);
		exit (1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;
	int 		i;
	int			j;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hello!");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return(MLX_ERROR);
	}
	data.img_data_ptr = malloc(sizeof(t_data)); // Asignar memoria para img_data_ptr
	if (!data.img_data_ptr)
	{
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	data.img_data_ptr->img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img_data_ptr->addr = mlx_get_data_addr(data.img_data_ptr->img, &(data.img_data_ptr->bpp), &(data.img_data_ptr->line_length), &(data.img_data_ptr->endian));
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{ 
			if (j >= 0 && j<= HEIGHT / 3 )
				my_mlx_pixel_put(data.img_data_ptr, i, j, 0x00FF0000);
			else if (j > HEIGHT / 3 && j<=  2 * HEIGHT / 3)
				my_mlx_pixel_put(data.img_data_ptr, i, j, 0x0000FF00);
			else
				my_mlx_pixel_put(data.img_data_ptr, i, j, 0x000000FF);
			i++;
		}
		j++;
	}		
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_data_ptr->img, 0, 0);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
}

/* int main(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	if (!mlx)
		return (MALLOC_ERROR);
	mlx_window = mlx_new_window(mlx, HEIGHT, WIDTH, "Helo world!");
	if (!mlx_window)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (MLX_ERROR);
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_window);
	mlx_destroy_display(mlx);
	free(mlx);
} */

/* int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hello world!");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return(MLX_ERROR);
	}
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
} */
