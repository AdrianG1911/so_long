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


char    get_move(int keycode)
{
    char    move;

    if (keycode == 65361)
        move = 'L';
    else if (keycode == 65362)
        move = 'U';
    else if (keycode == 65363)
        move = 'R';
    else if (keycode == 65364)
        move = 'D';
    else if (keycode == 65307)
        move = 'E';
    else
        move = 'N';
    return (move);
}

int key_press(int keycode, void *param)
{
    t_all   *all;
    char    move;

    all = (t_all *)param;
    move = get_move(keycode);
    if (move == 'N')
        return (0);
    if (move_eat_finish(all->game, move) == 1)
        move = 'F';
    update_map(all, all->game->dol_x, all->game->dol_y);
    render_dolphin(all);
    if (move != 'E')
        printf("Moves: %d\n", all->game->moves_done);
    if (move == 'E' || move == 'F')
    {
        mlx_destroy_window(all->mlx, all->win);
        free_all(all);
        exit(0);
    }
    return (0);
}

int close_window(void *param)
{
    t_all   *all;

    all = (t_all *)param;
    mlx_destroy_window(all->mlx, all->win);
	free_all(all);
    exit(0);
	return (0);
}

int memerror_free(int error, t_all *all)
{
    if (error == ENOMEM)
		ft_putstr_fd("Error\nnot enough memory\n", STDERR_FILENO);
	else
		ft_putstr_fd("", STDERR_FILENO);
    free_all(all);
    return (1);
}

int main(int argc, char *argv[])
{
    void        *mlx;
    void        *win;
    t_all       *all;

    if (argc != 2)
        return (ft_putendl_fd("Error\nneed map path as argument", STDERR_FILENO), 1);
    mlx = mlx_init();
    if (!mlx)
        return (ft_putendl_fd("Error\nmlx fail", STDERR_FILENO), 1);
    all = init_all(mlx, argv[1]);
    if (!all)
        return (memerror_free(errno, all));
    win = mlx_new_window(mlx, all->game->map_w * 32, all->game->map_h * 32, "Thanks!");
    if (!win)
        return (memerror_free(errno, all));
    all->win = win;
    render_g_map(all);
    render_dolphin(all);
    mlx_key_hook(win, key_press, (void *)all);
	mlx_hook(win, 17, 0, close_window, (void *)all);
    mlx_loop(mlx);
    return (0);
}
