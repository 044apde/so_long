/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:25:32 by shikim            #+#    #+#             */
/*   Updated: 2023/06/07 21:28:56 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_path(t_map *mapbox)
{
	int		map_size;
	t_queue	*queue;

	map_size = mapbox->width * mapbox->height;
	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->p_position = (t_position **)malloc(map_size * sizeof(t_position *));
	queue->front = 0;
	queue->rear = 0;
}
