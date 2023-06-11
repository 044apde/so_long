/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:25:32 by shikim            #+#    #+#             */
/*   Updated: 2023/06/11 15:43:01 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_cqueue(t_cqueue *queue, t_map *mapbox)
{
	queue->front = 0;
	queue->rear = 0;
	enqueue(queue, mapbox->p_y, mapbox->p_x, mapbox);
	mapbox->visited[mapbox->p_y][mapbox->p_x] = 'Y';
	return ;
}

int	is_empty(t_cqueue *queue)
{
	if (queue->front == queue->rear)
		return (TRUE);
	return (FALSE);
}

int	is_full(t_cqueue *queue)
{
	if ((queue->rear + 1) % MAX == queue->front)
		return (TRUE);
	return (FALSE);
}

void	enqueue(t_cqueue *queue, int m_y, int m_x, t_map *mapbox)
{
	if (is_full(queue) == TRUE)
		exit(1);
	queue->rear = (queue->rear + 1) % MAX;
	queue->p_position[queue->rear].x = m_x;
	queue->p_position[queue->rear].y = m_y;
	mapbox->visited[m_y][m_x] = 'Y';
}

t_position	*dequeue(t_cqueue *queue)
{
	if (is_empty(queue) == TRUE)
		return (NULL);
	queue->front = (queue->front + 1) % MAX;
	return (&queue->p_position[queue->front]);
}
