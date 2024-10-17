#include "so_long.h"

int			load_image(void	*mlx, t_textures *tts, void **t, char *tts_name)
{
	char	path[25];
	int		w;
	int		h;

	ft_bzero(path, sizeof(path));
	ft_strlcat(path, "textures/", 25);
	ft_strlcat(path, tts_name, 25);
	ft_strlcat(path, ".xpm", 25);
	*t = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!(*t))
		return (ft_putendl_fd("Error\ntexture error", STDERR_FILENO), free_textures(mlx, tts), -1);
	return (1);
}

int		load_data(void	*mlx, t_textures *tts)
{
	tts->dolphin_data = mlx_get_data_addr(tts->dolphin, &(tts->d_bpp), &(tts->d_sl), &(tts->d_endian));
	if (!tts->dolphin_data)
		return (ft_putendl_fd("Error\ntexture error", STDERR_FILENO), free_textures(mlx, tts), -1);
	return (1);
}

t_textures	*init_textures(void *mlx)
{
	t_textures	*tts;

	tts = (t_textures *)ft_calloc(1, sizeof(t_textures));
	if (!tts)
		return (NULL);
	if (load_image(mlx, tts, &(tts->space), "space") == -1)
		return (NULL);
	if (load_image(mlx, tts, &(tts->wall), "wall") == -1)
		return (NULL);
	if (load_image(mlx, tts, &(tts->end), "end") == -1)
		return (NULL);
	if (load_image(mlx, tts, &(tts->fish), "fish") == -1)
		return (NULL);
	if (load_image(mlx, tts, &(tts->dolphin), "dolphin") == -1)
		return (NULL);
	if (load_data(mlx, tts) == -1)
		return (NULL);
	tts->width = 240;
	tts->height = 180;
	return (tts);
}
