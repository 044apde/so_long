/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:35:55 by shikim            #+#    #+#             */
/*   Updated: 2023/06/10 21:57:43 by shikim           ###   ########.fr       */
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
	int	w;

	h = -1;
	mapbox->visited = (char **)malloc(mapbox->height * sizeof(char *));
	if (mapbox->visited == NULL)
		exit_program();
	while (++h < mapbox->height)
	{
		w = -1;
		mapbox->visited[h] = (char *)malloc(mapbox->width + 1);
		if (mapbox->visited[h] == NULL)
		{
			free(mapbox->visited);
			mapbox->visited = NULL;
			exit_program();
		}
		while(++w < mapbox->width)
			mapbox->visited[h][w] = 'N';
	}
}

void	check_path(t_map *mapbox)
{
	int				x;
	int				y;
	t_cqueue		queue;
	t_position		*coordinate;

	init_cqueue(&queue, mapbox);
	make_visited(mapbox);
	enqueue(&queue, mapbox->p_x, mapbox->p_y);
	while(is_empty(&queue) == FALSE)
	{
		coordinate = dequeue(&queue);
		x = coordinate->x;
		y = coordinate->y;
		ft_printf("%d %d\n", x, y);
	}
	return ;
}
