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

void	free_textures(void *mlx, t_textures *tts)
{
	if (tts)
	{
		if (tts->space)
			mlx_destroy_image(mlx, tts->space);
		if (tts->wall)
			mlx_destroy_image(mlx, tts->wall);
		if (tts->end)
			mlx_destroy_image(mlx, tts->end);
		if (tts->fish)
			mlx_destroy_image(mlx, tts->fish);
		if (tts->dolphin)
			mlx_destroy_image(mlx, tts->dolphin);
		free(tts);
	}
}

void	free_all(t_all *all)
{
	if (all)
	{
		free_game(all->game);
		free_textures(all->mlx, all->textures);
		mlx_destroy_display(all->mlx);
		free(all->mlx);
		free(all);
	}
}