/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:35:55 by shikim            #+#    #+#             */
/*   Updated: 2023/06/11 15:22:59 by shikim           ###   ########.fr       */
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
		mapbox->visited[h] = (char *)malloc(mapbox->width * sizeof(char));
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
	int				i;
	int				move_x;
	int				move_y;
	t_cqueue		queue;
	t_position		*coordinate;

	make_visited(mapbox);
	init_cqueue(&queue, mapbox);
	while(is_empty(&queue) == FALSE)
	{
		i = -1;
		coordinate = dequeue(&queue);
		if (mapbox->map[coordinate->y][coordinate->x] == 'E')
			return ;
		while (++i < 4)
		{
			move_x = move_horizontally(i) + coordinate->x;
			move_y = move_vertically(i) + coordinate->y;
			if(move_x <= 0 || move_y <= 0 || move_x >= mapbox->width - 1 \
				|| move_y >= mapbox->height - 1 || mapbox->map[move_y][move_x] == '1' \
					|| mapbox->visited[move_y][move_x] == 'Y')
				continue;
			enqueue(&queue, move_x, move_y);
			mapbox->visited[move_y][move_x] = 'Y';
		}
	}
	ft_printf("Error! There is no path to Exit.\n");
	exit(1);
}
