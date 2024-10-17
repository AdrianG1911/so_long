#include "so_long.h"

char	**dup_g_map(char **g_map)
{
	int		i;
	char	**duped;

	i = 0;
	while (g_map[i])
		i++;
	duped = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!duped)
		return (NULL);
	i = 0;
	while (g_map[i])
	{
		duped[i] = ft_strdup(g_map[i]);
		if (!duped[i])
			return (free_g_map(duped), NULL);
		i++;
	}
	return (duped);
}

void	filldupmap(char	**duped, int x, int y)
{
	if (duped[y][x] == '1' || duped[y][x] == 'f')
		return	;
	duped[y][x] = 'f';
	filldupmap(duped, x + 1, y);
	filldupmap(duped, x, y + 1);
	filldupmap(duped, x - 1, y);
	filldupmap(duped, x, y - 1);
}

int	is_completable(char **duped)
{
	int	i;
	int	j;

	i = 0;
	while (duped[i])
	{
		j = 0;
		while (duped[i][j])
		{
			if (duped[i][j] == 'E' || duped[i][j] == 'C')
				return (free_g_map(duped), -1);
			j++;
		}
		i++;
	}
	return (free_g_map(duped), 1);
}

int	completable_check(char	**g_map)
{
	char	**duped;
	int		x;
	int		y;

	duped = dup_g_map(g_map);
	if (!duped)
		return (-1);
	y = -1;
	while (duped[++y])
	{
		x = 0;
		while (duped[y][x])
		{
			if (duped[y][x] == 'P')
				break ;
			x++;
		}
		if (duped[y][x] == 'P')
			break ;
	}
	filldupmap(duped, x, y);
	if (is_completable(duped) == -1)
		return (ft_putendl_fd("Error\nmap not completable", STDERR_FILENO), -1);
	return (1);
}
