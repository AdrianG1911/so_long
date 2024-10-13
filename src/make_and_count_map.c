#include "so_long.h"

int	count_rows(const char *g_mapfile)
{
	int		fd;
	char	c;
	int		lineCount;
	ssize_t	bytesRead;

	fd = open(g_mapfile, O_RDONLY);
	if (fd == -1)
		return (perror(g_mapfile), -1);
	lineCount = 0;
	while (1)
	{
		bytesRead = read(fd, &c, 1);
		if (bytesRead < 0)
			return (perror("Read error"), close(fd), -1);
		if (bytesRead == 0)
			break ;
		if (c == '\n')
			lineCount++;
	}
	close(fd);
	return (lineCount);
}

int	count_columns(const char *g_mapfile)
{
	int		fd;
	char	c;
	int		columnCount;
	ssize_t	bytesRead;

	fd = open(g_mapfile, O_RDONLY);
	if (fd == -1)
		return (perror(g_mapfile), -1);
	columnCount = 0;
	while (1)
	{
		bytesRead = read(fd, &c, 1);
		if (bytesRead < 0)
			return (perror("Read error"), close(fd), -1);
		if (c == '\n')
			break ;
		columnCount++;
	}
	close(fd);
	return (columnCount);
}

int	count_r_and_c(const char *g_mapfile,int *r_and_c)
{
	r_and_c[0] = count_rows(g_mapfile);
	if (r_and_c[0] == -1)
		return (-1);
	r_and_c[1] = count_columns(g_mapfile);
	if (r_and_c[1] == -1)
		return (-1);
	return (1);
}

char	**make_array(int *r_and_c)
{
	char	**g_map;
	int		i;

	g_map = (char **)ft_calloc(r_and_c[0] + 1, sizeof(char *));
	if (!g_map)
		return (NULL);
	i = 0;
	while (i < r_and_c[0])
	{
		g_map[i] = (char *)ft_calloc(r_and_c[1] + 1, sizeof(char));
		if (!g_map[i])
			return (free_g_map(g_map), NULL);
		i++;
	}
	return (g_map);
}

char	**read_g_map(const char *g_mapfile)
{
	char	**g_map;
	int		r_and_c[2];
	int		fd;
	int		i;

	fd = open(g_mapfile, O_RDONLY);
	if (fd == -1)
		return (perror(g_mapfile), NULL);
	if (count_r_and_c(g_mapfile, r_and_c) == -1)
	 	return (close(fd), NULL);
	g_map = make_array(r_and_c);
	if (!g_map)
		return (close(fd), NULL);
	i = 0;
	while (i < r_and_c[0])
	{
		if (read(fd, g_map[i], r_and_c[1] + 1) < r_and_c[1] + 1)
			return (perror("Read error"), free_g_map(g_map), close(fd), NULL);
		g_map[i][r_and_c[1]] = 0;
		i++;
	}
	close(fd);
	return (g_map);
}
