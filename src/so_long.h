/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:37:51 by adrgutie          #+#    #+#             */
/*   Updated: 2024/10/08 20:53:36 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>

//game structure
typedef struct	s_game
{
	char	**g_map;
	int		x_pos;
	int		y_pos;
	char	face_dir;
	int		fish_left;
	int		moves_done;
}	t_game;

//game
void	free_game(t_game *game);

//mapstuff
void	free_g_map(char **g_map);
char	**read_g_map(const char *g_mapfile);

//check
int		outer_wall(char	**g_map);
int		completable_check(char	**g_map)
#endif