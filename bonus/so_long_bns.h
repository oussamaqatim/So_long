/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bns.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:58:06 by oqatim            #+#    #+#             */
/*   Updated: 2022/04/23 10:50:01 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BNS_H
# define SO_LONG_BNS_H 

# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_gnl
{
	char	*gnl;
	char	*buff;
}	t_gnl;

typedef struct s_map
{
	char	**map;
	int		largeur;
	int		longeur;
	void	*test;
	void	*mlx_ptr;
	void	*mlx_win;
	int		c;
	int		p;
	int		e;
	int		position_x;
	int		position_y;
	int		count_move;
}	t_map;

void	so_long(char *path);
char	*ft_read(int fd, char **line);
int		parse_map(t_map *map, int k);
void	ft_bg(t_map *map, int i, int j, char *link);
void	position_player(t_map *map);
int		count_collect(t_map *map);
int		ft_mouvement(int key, t_map *map);
void	ft_left(t_map *map, int k);
void	ft_lisser(t_map *map, int k);
void	ft_ltaht(t_map *map, int k);
void	ft_lfoug(t_map *map, int k);
char	*ft_itoa(int n);
size_t	count(int n);
void	count_screen(t_map *map);
void	ft_count_move(t_map *map);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_move_sayad(t_map *map, int k);
int		ft_exit(t_map *map);
void	check_extension_map(char *path);

#endif