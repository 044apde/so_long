/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:25:32 by shikim            #+#    #+#             */
/*   Updated: 2023/06/10 19:33:33 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_cqueue(t_cqueue *queue, t_map *mapbox)
{
	queue->front = 0;
	ft_printf("init queue front: %d\n", queue->front);
	queue->rear = 0;
	ft_printf("init queue rear: %d\n", queue->rear);
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

void	enqueue(t_cqueue *queue, int x, int y)
{
	if (is_full(queue) == TRUE)
	{
		ft_printf("Queue is full. abnormal accident. exit program.\n");
		exit(1);
	}
	queue->rear = (queue->rear + 1) % MAX;
	queue->p_position[queue->rear].x = x;
	queue->p_position[queue->rear].y = y;
}

t_position	*dequeue(t_cqueue *queue)
{
	if (is_empty(queue) == TRUE)
	{
		ft_printf("Queue is empty.\n");
		return (NULL);
	}
	queue->front = (queue->front + 1) % MAX;
	ft_printf("---\n");
	ft_printf("%d %d\n", queue->p_position[queue->front].x, queue->p_position[queue->front].x);
	return (&queue->p_position[queue->front]);
}
