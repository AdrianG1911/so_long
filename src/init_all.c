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
	all->textures = init_textures(mlx);
	if (!all->textures)
		return (free_all(all), NULL);
	return (all);
}