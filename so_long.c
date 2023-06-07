/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:59:04 by shikim            #+#    #+#             */
/*   Updated: 2023/06/07 16:06:31 by shikim           ###   ########.fr       */
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
	check_path_to_end(mapbox);
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
