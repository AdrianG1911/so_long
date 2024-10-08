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

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (EXIT_FAILURE);
	win = mlx_new_window(mlx, 800, 600, "My Window");
	if (!win)
		return (EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	return (0);
}
