/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 01:28:41 by oqatim            #+#    #+#             */
/*   Updated: 2022/04/23 10:56:25 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bns.h"

void	ft_move_sayad(t_map *map, int k)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->longeur)
	{
		j = -1;
		while (++j < map->largeur)
		{
			if (map->map[i][j] == 'S')
			{
				if (k % 2 == 0)
					ft_bg(map, i, j, "img/sayad.xpm");
				else
					ft_bg(map, i, j, "img/sayad2.xpm");
			}
		}
	}
}

int	parse_map(t_map *map, int k)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(map->mlx_ptr, map->mlx_win);
	while (++i < map->longeur)
	{
		j = -1;
		while (++j < map->largeur)
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
			else if (map->map[i][j] == 'S')
				ft_move_sayad(map, k);
		}
	}
	return (0);
}

void	ft_bg(t_map *map, int i, int j, char *link)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	count_screen(map);
	map->test = mlx_xpm_file_to_image(map->mlx_ptr, link, &width, &height);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win,
		map->test, j * 64, i * 64);
	mlx_destroy_image(map->mlx_ptr, map->test);
}

void	ft_count_move(t_map *map)
{
	map->count_move += 1;
}

void	count_screen(t_map *map)
{
	char	*nb;

	nb = ft_itoa(map->count_move);
	mlx_string_put(map->mlx_ptr, map->mlx_win, 25, 15, 0xFFFFF, "Moves : ");
	mlx_string_put(map->mlx_ptr, map->mlx_win, 100, 15, 0xFFFFF, nb);
	free(nb);
}
