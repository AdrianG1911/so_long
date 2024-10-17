#include "so_long.h"

void	g_move(t_game *game, char move_dir)
{
	int	x;
	int	y;

	if (move_dir == 'L' || move_dir == 'R')
		game->face_dir = move_dir;
	x = 0;
	y = 0;
	if (move_dir == 'L')
		x = -1;
	else if (move_dir == 'R')
		x = 1;
	else if (move_dir == 'U')
		y = -1;
	else if (move_dir == 'D')
		y = 1;
	if (game->g_map[game->dol_y + y][game->dol_x + x] == '1')
		return ;
	game->dol_y += y;
	game->dol_x += x;
	game->moves_done++;
}

void	fish_eat_check(t_game *game)
{
	if (game->g_map[game->dol_y][game->dol_x] != 'C')
		return ;
	game->g_map[game->dol_y][game->dol_x] = '0';
	game->fish_left--;
}

int		finish_check(t_game *game)
{
	if (game->g_map[game->dol_y][game->dol_x] != 'E')
		return (-1);
	if (game->fish_left > 0)
		return (-1);
	return (1);
}

int		move_eat_finish(t_game *game, char move_dir)
{
	g_move(game, move_dir);
	fish_eat_check(game);
	if (finish_check(game) == -1)
		return (-1);
	return (1);
}