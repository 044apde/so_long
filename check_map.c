/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:28:35 by shikim            #+#    #+#             */
/*   Updated: 2023/06/07 11:43:47 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_reptition(t_map *mapbox)
{
	if (mapbox->flag_p == 0 || mapbox->flag_p > 1)
	{
		ft_printf("Error! starting point error in map.\n");
		exit(1);
	}
	if (mapbox->flag_e == 0 || mapbox->flag_e > 1)
	{
		ft_printf("Error! end point error in map.\n");
		exit(1);
	}
	if (mapbox->flag_c == 0)
	{
		ft_printf("Error! there is no collection in map.\n");
		exit(1);
	}
}

void	check_component(t_map *mapbox)
{
	int		h;
	int		w;
	char	*allowed_component;

	h = -1;
	allowed_component = "01CEP";
	while (++h < mapbox->height)
	{
		w = -1;
		while (++w < mapbox->width)
		{
			if (ft_strchr(allowed_component, mapbox->map[h][w]) == 0)
			{
				ft_printf("Error! map contains prohibited components.\n");
				exit(1);
			}
			if (mapbox->map[h][w] == 'E')
				++mapbox->flag_e;
			if (mapbox->map[h][w] == 'P')
				++mapbox->flag_p;
			if (mapbox->map[h][w] == 'C')
				++mapbox->flag_c;
		}
	}
}

void	check_wall(t_map *map_box)
{
	
}
