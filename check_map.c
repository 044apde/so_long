/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:28:35 by shikim            #+#    #+#             */
/*   Updated: 2023/06/07 16:07:46 by shikim           ###   ########.fr       */
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

void	check_wall(char *mapline)
{
	while (*mapline != '\n' && *mapline != '\0')
	{
		if (*mapline != '1')
		{
			ft_printf("Error! map edge is pierced.\n");
			exit(1);
		}
		mapline++;
	}
}

void	check_map_surround(t_map *mapbox)
{
	int	h;

	h = -1;
	check_wall(mapbox->map[0]);
	check_wall(mapbox->map[mapbox->height - 1]);
	while (++h < mapbox->height)
	{
		if (mapbox->map[h][0] != '1' || \
		mapbox->map[h][mapbox->width - 1] != '1')
		{
			ft_printf("%c", mapbox->map[h][0]);
			ft_printf("%c", mapbox->map[h][mapbox->height - 1]);
			ft_printf("Error! map edge is pierced.\n");
			exit(1);
		}
	}
}

void	check_path_to_end(t_map *mapbox)
{
}
