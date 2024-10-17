#include "so_long.h"


int	outer_wall(char	**g_map)
{
	int	i;
	int	j;

	j = -1;
	while (g_map[++j])
	{
		if (g_map[j][0] != '1')
			return (-1);
	}
	i = 0;
	while (g_map[0][i] == '1' && g_map[j - 1][i] == '1')
		i++;
	if (g_map[0][i] != 0)
		return (-1);
	j = -1;
	while (g_map[++j])
	{
		if (g_map[j][i - 1] != '1')
			return (-1);
	}
	return (1);
}
int	check_stuff(char tocheck, int *pefij)
{
	if (tocheck == 'P')
		pefij[0]++;
	else if (tocheck == 'E')
		pefij[1]++;
	else if (tocheck == 'C')
		pefij[2]++;
	else if (tocheck == '0')
		;
	else if (tocheck == '1')
		;
	else
		return (-1);
	return (1);
}

int	count_stuff(char **g_map)
{
	int	pefij[5];

	ft_bzero(pefij, sizeof(pefij));
	while (g_map[pefij[3]])
	{
		pefij[4] = 0;
		while (g_map[pefij[3]][pefij[4]])
		{
			if (check_stuff(g_map[pefij[3]][pefij[4]], pefij) == -1)
				return(ft_putendl_fd("Error\ninvalid char in map", STDERR_FILENO), -1);
			pefij[4]++;
		}
		pefij[3]++;			
	}
	if (pefij[0] != 1 || pefij[1] != 1)
		return (ft_putendl_fd("Error\nmap needs 1 start and end", STDERR_FILENO), -1);
	if (pefij[2] < 1)
		return (ft_putendl_fd("Error\nmap needs 1 or more fish", STDERR_FILENO), -1);
	return (1);
}

int	g_map_checker(char **g_map)
{
	if (outer_wall(g_map) == -1)
		return (ft_putendl_fd("Error\nouter wall rectangle needed", STDERR_FILENO), -1);
	if (count_stuff(g_map) == -1)
		return (-1);
	// if (completable_check(g_map) == -1)
	// 	return (-1);
	return (1);
}
