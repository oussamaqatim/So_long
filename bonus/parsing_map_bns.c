/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:17:22 by oqatim            #+#    #+#             */
/*   Updated: 2022/04/23 10:49:28 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bns.h"

void	check_map(char *file, t_map *map)
{
	int		fd;
	char	*line;

	map->longeur = 0;
	check_extension_map(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Map error\n");
		exit(1);
	}
	line = get_next_line(fd);
	map->largeur = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->longeur++;
	}
	free (line);
}

void	check_caractere(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->longeur)
	{
		j = 0;
		while (++j < map->largeur)
		{
			if (map->map[i][j] == 'C')
				map->c++;
			if (map->map[i][j] == 'E')
				map->e++;
			if (map->map[i][j] == 'P')
				map->p++;
		}
	}
	if (map->c < 1 || map->e < 1 || map->p != 1)
	{
		printf("khobza100\n");
		exit(1);
	}
}

void	check_wall_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->longeur)
	{
		if (map->map[i][0] != '1' || map->map[i][map->largeur - 1] != '1')
		{
			printf("khobza1");
			exit(1);
		}
	}
	j = -1;
	while (++j < map->largeur)
	{
		if (map->map[0][j] != '1' || map->map[map->longeur - 1][j] != '1')
		{
			printf("khobza2");
			exit(1);
		}
	}
	check_caractere (map);
}

void	check_line(t_map *map)
{
	int	i;

	i = -1;
	map->c = 0;
	map->e = 0;
	map->p = 0;
	map->count_move = 0;
	while (++i < map->longeur - 1)
	{
		if (ft_strlen(map->map[i]) != ft_strlen(map->map[i + 1]))
		{
			printf("khobzaoness");
			exit(1);
		}
	}
}

void	so_long(char *path)
{
	int		i;
	int		fd;
	t_map	map;

	i = -1;
	check_map(path, &map);
	fd = open (path, O_RDONLY);
	map.map = (char **)malloc(sizeof(char *) * map.longeur);
	map.map[map.longeur] = NULL;
	while (++i < map.longeur)
		map.map[i] = get_next_line(fd);
	check_line(&map);
	check_wall_map(&map);
	map.mlx_ptr = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx_ptr,
			(map.largeur * 64), (map.longeur * 64), "so_long");
	parse_map(&map, 0);
	mlx_hook(map.mlx_win, 2, 0, ft_mouvement, &map);
	mlx_hook(map.mlx_win, 17, 0, ft_exit, &map);
	mlx_loop(map.mlx_ptr);
}
