/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:08:14 by shikim            #+#    #+#             */
/*   Updated: 2023/06/14 22:03:39 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_all(t_all *all, t_map *mapbox, t_imgbox *imgbox, t_position *player_position)
{
	all->imgbox = imgbox;
	all->mapbox = mapbox;
	all->player_position = player_position;
	all->player_position->x = mapbox->p_x;
	all->player_position->y = mapbox->p_y;
	return ;
}

int	ft_maplen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != 0 && s[length] != '\n')
		++length;
	return (length);
}

int	open_map(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error! fail to open map_file.\n");
		exit(1);
	}
	return (fd);
}

void	exit_program(void)
{
	ft_printf("Error! fail to malloc.\n");
	exit(1);
}
