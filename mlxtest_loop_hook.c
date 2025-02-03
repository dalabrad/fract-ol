/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtest_loop_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:08:33 by dalabrad          #+#    #+#             */
/*   Updated: 2025/02/03 11:37:34 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct  s_data {
    void        *mlx;
    void        *win;
    int         color;
}               t_data;


int f(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        printf("Pressed Esc\n");
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
    	exit(1);
    }
    printf("Pressed %d\n", keysym);
    //sleep to appreciate loop_hook stopping
    sleep(1);
    return 1;
}



int     change_color(t_data *data)
{
    // Fill the window with the current color
//  mlx_clear_window(data->mlx, data->win);
    mlx_string_put(data->mlx, data->win, 150, 150, data->color, "Color Changing Window!");

    // Cycle through some basic colors: RED, GREEN, BLUE
    if (data->color == 0xFF0000)        // If it's red
        data->color = 0x00FF00;        // Change to green
    else if (data->color == 0x00FF00)   // If it's green
        data->color = 0x0000FF;        // Change to blue
    else
        data->color = 0xFF0000;        // Otherwise, go back to red

    return (0);
}

int     main(void)
{
    t_data  data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 
            400,
            400, 
            "Sample Window");
    data.color = 0xFF0000;  // Start with red color

    mlx_key_hook(data.win,
                f, 
                &data);


    mlx_loop_hook(data.mlx,
             change_color,
             &data);
    mlx_loop(data.mlx);

    return (0);
}
