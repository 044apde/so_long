/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:35:55 by shikim            #+#    #+#             */
/*   Updated: 2023/06/10 17:32:55 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_horizontally(int i)
{
	if (i == 0)
		return (0);
	if (i == 1)
		return (0);
	if (i == 2)
		return (-1);
	if (i == 3)
		return (1);
	return (FALSE);
}

int	move_vertically(int i)
{
	if (i == 0)
		return (-1);
	if (i == 1)
		return (1);
	if (i == 2)
		return (0);
	if (i == 3)
		return (0);
	return (FALSE);
}

void	make_visited(t_map *mapbox)
{
	int	h;

	h = -1;
	mapbox->visited = (char **)malloc(mapbox->height);
	if (mapbox->visited == NULL)
		exit_program();
	while (++h < mapbox->height)
	{
		mapbox->visited[h] = (char *)malloc(mapbox->width);
		if (mapbox->visited[h] == NULL)
		{
			free(mapbox->visited);
			mapbox->visited = NULL;
			exit_program();
		}
		ft_printf("%p\n", mapbox->visited[h][0]);
	}
}

void	check_path(t_map *mapbox)
{
	t_cqueue queue;

	init_cqueue(&queue, mapbox);
	return ;
}