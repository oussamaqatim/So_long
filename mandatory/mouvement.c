/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:04:52 by oqatim            #+#    #+#             */
/*   Updated: 2022/04/23 10:28:53 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouvement(int key, t_map *map)
{
	if (key == 2)
		ft_left(map);
	if (key == 0)
		ft_lisser(map);
	if (key == 1)
		ft_ltaht(map);
	if (key == 13)
		ft_lfoug(map);
	if (key == 53)
		exit(1);
	return (0);
}

void	ft_left(t_map *map)
{
	int	i;
	int	j;

	position_player(map);
	i = map->position_x;
	j = map->position_y;
	if (map->map[i][j + 1] == '0' || map->map[i][j + 1] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i][j + 1] = 'P';
		ft_count_move(map);
		parse_map(map);
	}
	else if (count_collect(map) == 0 && map->map[i][j + 1] == 'E')
	{
		ft_count_move(map);
		exit(1);
	}
}

void	ft_lisser(t_map *map)
{
	int	i;
	int	j;

	position_player(map);
	i = map->position_x;
	j = map->position_y;
	if (map->map[i][j - 1] == '0' || map->map[i][j - 1] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i][j - 1] = 'P';
		ft_count_move(map);
		parse_map(map);
	}
	else if (count_collect(map) == 0 && map->map[i - 1][j] == 'E')
	{
		ft_count_move(map);
		exit(1);
	}
}

void	ft_ltaht(t_map *map)
{
	int	i;
	int	j;		

	position_player(map);
	i = map->position_x;
	j = map->position_y;
	if (map->map[i + 1][j] == '0' || map->map[i + 1][j] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i + 1][j] = 'P';
		ft_count_move(map);
		parse_map(map);
	}
	else if (count_collect(map) == 0 && map->map[i + 1][j] == 'E')
	{
		ft_count_move(map);
		exit(1);
	}
}

void	ft_lfoug(t_map *map)
{
	int	i;
	int	j;		

	position_player(map);
	i = map->position_x;
	j = map->position_y;
	if (map->map[i - 1][j] == '0' || map->map[i - 1][j] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i - 1][j] = 'P';
		ft_count_move(map);
		parse_map(map);
	}
	else if (count_collect(map) == 0 && map->map[i - 1][j] == 'E')
	{
		ft_count_move(map);
		exit(1);
	}
}
