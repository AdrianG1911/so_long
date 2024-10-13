/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:35:34 by adrgutie          #+#    #+#             */
/*   Updated: 2024/10/08 20:53:34 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int escape_press(int keycode, void *param)
{
	(void)param;
    printf("Key pressed: %d\n", keycode);
    if (keycode == 65307)
        exit(0);
    return (0);
}

int close_window(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(0);
	return (0);
}

int rip(void *mlx, void *window)
{
    mlx_destroy_window(mlx, window);
    exit(0);
    return (1);
}

int main(void)
{
    void    *mlx;
    void    *window;
    char    **g_map;

    g_map = read_g_map("maps/map1.ber");
    if (g_map == NULL)
        return (ft_putstr_fd("Error\nmap not read properly\n", STDERR_FILENO), 1);
    ft_printf("%d\n", outer_wall(g_map));
    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "Test Window");
    // Handle keypresses and window close events
    mlx_key_hook(window, escape_press, NULL);
	mlx_hook(window, 17, 0, close_window, NULL);
    rip(mlx, window);
    mlx_loop(mlx);
    free(g_map);
    return (0);
}