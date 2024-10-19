/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:00:38 by adrgutie          #+#    #+#             */
/*   Updated: 2024/10/19 17:31:36 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_ppos_and_fishcount(t_game *game)
{
	int	x;
	int	y;

	game->fish_left = 0;
	y = 0;
	while (game->g_map[y])
	{
		x = 0;
		while (game->g_map[y][x])
		{
			if (game->g_map[y][x] == 'P')
			{
				game->dol_x = x;
				game->dol_y = y;
			}
			if (game->g_map[y][x] == 'C')
				game->fish_left++;
			x++;
		}
		y++;
	}
}

void	get_map_size(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->g_map[y])
		y++;
	while (game->g_map[0][x])
		x++;
	game->map_h = y;
	game->map_w = x;
}

t_game	*init_game(const char *g_mapfile)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->g_map = read_g_map(g_mapfile);
	if (game->g_map == NULL)
		return (free_game(game), NULL);
	if (g_map_checker(game->g_map) == -1)
		return (free_game(game), NULL);
	find_ppos_and_fishcount(game);
	game->face_dir = 'L';
	game->moves_done = 0;
	get_map_size(game);
	return (game);
}
