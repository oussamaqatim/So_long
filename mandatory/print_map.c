/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 01:28:41 by oqatim            #+#    #+#             */
/*   Updated: 2022/04/26 17:47:07 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(map->mlx_ptr, map->mlx_win);
	while (i < map->longeur)
	{
		j = 0;
		while (j < map->largeur)
		{
			if (map->map[i][j] == '0')
				ft_bg(map, i, j, "img/background.xpm");
			if (map->map[i][j] == '1')
				ft_bg(map, i, j, "img/Wall.xpm");
			else if (map->map[i][j] == 'P')
				ft_bg(map, i, j, "img/player.xpm");
			else if (map->map[i][j] == 'C')
				ft_bg(map, i, j, "img/collect.xpm");
			else if (map->map[i][j] == 'E')
				ft_bg(map, i, j, "img/exit.xpm");
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_bg(t_map *map, int i, int j, char *link)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	map->test = mlx_xpm_file_to_image(map->mlx_ptr, link, &width, &height);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->test, j * 64, i * 64);
}

void	ft_count_move(t_map *map)
{
	map->count_move += 1;
	ft_putnbr_fd(map->count_move, 1);
	ft_putstr_fd("\n", 1);
}

void	check_extension_map(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'r' || path[i - 2] != 'e'
		|| path[i - 3] != 'b' || path[i - 4] != '.')
	{
		printf("error map \n");
		exit(1);
	}
}

int	ft_exit(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	exit(0);
}
