/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:00:42 by adrgutie          #+#    #+#             */
/*   Updated: 2024/10/19 17:40:11 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_all	*init_all(void *mlx, const char *g_mapfile)
{
	t_all	*all;

	all = (t_all *)ft_calloc(1, sizeof(t_all));
	if (!all)
		return (NULL);
	all->mlx = mlx;
	all->game = init_game(g_mapfile);
	if (!all->game)
		return (free_all(all), NULL);
	all->tts = init_textures(mlx);
	if (!all->tts)
		return (free_all(all), NULL);
	return (all);
}
