#include "so_long.h"

void	free_g_map(char **g_map)
{
	int	i;

	if (g_map)
	{
		i = 0;
		while (g_map[i])
		{
			free(g_map[i]);
			i++;
		}
		free(g_map);
	}
}

void	free_game(t_game *game)
{
	if (game)
	{
		free_g_map(game->g_map);
		free(game);
	}
}
