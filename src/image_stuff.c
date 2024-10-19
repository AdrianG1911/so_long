/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:00:46 by adrgutie          #+#    #+#             */
/*   Updated: 2024/10/19 17:40:57 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_image(char tile, t_all *all)
{
	if (tile == 'C')
		return (all->tts->fish);
	if (tile == 'E')
		return (all->tts->end);
	if (tile == 'P' || tile == '0')
		return (all->tts->space);
	if (tile == '1')
		return (all->tts->wall);
	return (NULL);
}

void	render_g_map(t_all *all)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < all->game->map_h)
	{
		x = 0;
		while (x < all->game->map_w)
		{
			img = get_image(all->game->g_map[y][x], all);
			mlx_put_image_to_window(all->mlx, all->win, img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	draw_dolphin(t_all *all, int x_s, int y_s, char facing)
{
	int	x;
	int	truex;
	int	y;
	int	pixel_index;
	int	color;

	y = 0;
	while (y < 32)
	{
		x = 0;
		while (x < 32)
		{
			if (facing == 'L')
				truex = abs(x - 31);
			else
				truex = x;
			pixel_index = y * all->tts->d_sl + x * (all->tts->d_bpp / 8);
			color = *(int *)(all->tts->dolphin_data + pixel_index);
			if (color != 0xFFFFFF)
				mlx_pixel_put(all->mlx, all->win, truex + x_s, y + y_s, color);
			x++;
		}
		y++;
	}
}

void	render_dolphin(t_all *all)
{
	char	facing;
	int		x_strt;
	int		y_strt;

	facing = all->game->face_dir;
	x_strt = all->game->dol_x * 32;
	y_strt = all->game->dol_y * 32;
	draw_dolphin(all, x_strt, y_strt, facing);
}

void	update_map(t_all *all, int x, int y)
{
	void	*img;

	img = get_image(all->game->g_map[y][x], all);
	mlx_put_image_to_window(all->mlx, all->win, img, x * 32, y * 32);
	img = get_image(all->game->g_map[y][x + 1], all);
	mlx_put_image_to_window(all->mlx, all->win, img, (x + 1) * 32, y * 32);
	img = get_image(all->game->g_map[y][x - 1], all);
	mlx_put_image_to_window(all->mlx, all->win, img, (x - 1) * 32, y * 32);
	img = get_image(all->game->g_map[y + 1][x], all);
	mlx_put_image_to_window(all->mlx, all->win, img, x * 32, (y + 1) * 32);
	img = get_image(all->game->g_map[y - 1][x], all);
	mlx_put_image_to_window(all->mlx, all->win, img, x * 32, (y - 1) * 32);
}
