/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:59:04 by shikim            #+#    #+#             */
/*   Updated: 2023/06/11 15:47:30 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*parse_map(char *map_name)
{
	t_map	*mapbox;
	char	*map_path;

	check_mapname(map_name);
	mapbox = (t_map *)malloc(sizeof(t_map));
	map_path = ft_strjoin("./maps/", map_name);
	if (map_path == NULL)
		exit_program();
	set_mapbox_size(mapbox, map_path);
	set_mapbox_map(mapbox, map_path);
	set_mapbox_point(mapbox);
	return (mapbox);
}

void	check_map(t_map *mapbox)
{
	check_component(mapbox);
	check_reptition(mapbox);
	check_map_surround(mapbox);
	if (check_path(mapbox) == FALSE)
	{
		ft_printf("Error! there is no path.\n");
		exit(1);
	}
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
