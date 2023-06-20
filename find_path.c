/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:35:55 by shikim            #+#    #+#             */
/*   Updated: 2023/06/20 18:23:05 by shikim           ###   ########.fr       */
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
			exit_program();
		while (++w < mapbox->width)
			mapbox->visited[h][w] = 'N';
	}
}

int	check_path(t_map *mb)
{
	int				i;
	int				m_x;
	int				m_y;
	t_cqueue		queue;
	t_position		*coordinate;

	make_visited(mb);
	init_cqueue(&queue, mb);
	while (is_empty(&queue) == FALSE)
	{
		i = -1;
		coordinate = dequeue(&queue);
		if (mb->map[coordinate->y][coordinate->x] == 'E')
			return (TRUE);
		while (++i < 4)
		{
			m_x = move_horizontally(i) + coordinate->x;
			m_y = move_vertically(i) + coordinate->y;
			if (m_x <= 0 || m_y <= 0 || m_x > mb->width || m_y > mb->height || \
				mb->map[m_y][m_x] == '1' || mb->visited[m_y][m_x] == 'Y')
				continue ;
			enqueue(&queue, m_y, m_x, mb);
		}
	}
	return (FALSE);
}
