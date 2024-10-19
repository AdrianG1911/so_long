/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:37:51 by adrgutie          #+#    #+#             */
/*   Updated: 2024/10/19 17:34:57 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>

//game structure
typedef struct s_game
{
	char	**g_map;
	int		dol_x;
	int		dol_y;
	char	face_dir;
	int		fish_left;
	int		moves_done;
	int		map_w;
	int		map_h;
}	t_game;

typedef struct s_tts
{
	void	*space;
	void	*wall;
	void	*end;
	void	*fish;
	void	*dolphin;
	void	*dolphin_data;
	int		d_bpp;
	int		d_sl;
	int		d_endian;
	int		width;
	int		height;
}	t_tts;

typedef struct s_all
{
	void		*mlx;
	void		*win;
	t_game		*game;
	t_tts		*tts;
}	t_all;

//game
t_game		*init_game(const char *g_mapfile);
void		free_game(t_game *game);

//mapstuff
void		free_g_map(char **g_map);
char		**read_g_map(const char *g_mapfile);
int			count_rows(const char *g_mapfile);
int			count_columns(const char *g_mapfile);

//check
int			g_map_checker(char **g_map);
int			outer_wall(char	**g_map);
int			completable_check(char	**g_map);

//textures
t_tts		*init_textures(void *mlx);
void		free_textures(void *mlx, t_tts *tts);

//all
t_all		*init_all(void *mlx, const char *g_mapfile);
void		free_all(t_all *all);

//render
void		render_g_map(t_all *all);
void		render_dolphin(t_all *all);
void		update_map(t_all *all, int x, int y);

//play
int			move_eat_finish(t_game *game, char move_dir);

#endif