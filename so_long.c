/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:59:04 by shikim            #+#    #+#             */
/*   Updated: 2023/06/07 21:30:55 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*parse_map(char *map_name)
{
	t_map	*mapbox;
	char	*map_path;

	check_mapname(map_name);
	mapbox = (t_map *)malloc(sizeof(t_map));
	map_path = ft_strjoin("./assets/maps/", map_name);
	set_mapbox_size(mapbox, map_path);
	set_mapbox_map(mapbox, map_path);
	set_mapbox_point(mapbox);
	ft_printf("exit : %d %d\n", mapbox->e_x, mapbox->e_y);
	ft_printf("start: %d %d\n", mapbox->p_x, mapbox->p_y);
	mapbox->flag_e = 0;
	mapbox->flag_p = 0;
	mapbox->flag_c = 0;
	return (mapbox);
}

void	check_map(t_map *mapbox)
{
	check_component(mapbox);
	check_reptition(mapbox);
	check_map_surround(mapbox);
	find_path(mapbox);
}

int	main(int ac, char **ag)
{
	int		fd;
	t_map	*mapbox;

	if (ac == 2)
	{
		mapbox = parse_map(ag[1]);
		check_map(mapbox);
	}
	else
		ft_printf("Error! require one map file.\n");
	return (0);
}
