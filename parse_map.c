/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:34:59 by shikim            #+#    #+#             */
/*   Updated: 2023/06/07 11:49:08 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_length(t_map *mapbox, char *map_path)
{
	int		fd;
	int		width;
	int		height;
	char	*buffer;

	fd = open_map(map_path);
	width = 0;
	height = 0;
	while (TRUE)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		if (width == 0)
			width = ft_maplen(buffer);
		else if (width != ft_maplen(buffer))
		{
			ft_printf("Error! map is not rectangle.\n");
			exit(1);
		}
		height++;
	}
	mapbox->width = width;
	mapbox->height = height;
	close(fd);
}

void	set_mapbox_size(t_map *mapbox, char *map_path)
{
	int	fd;

	fd = open_map(map_path);
	set_map_length(mapbox, map_path);
	if (mapbox->width == 0 || mapbox->height == 0)
	{
		ft_printf("Error! map file is empty.\n");
		exit(1);
	}
}

void	set_mapbox_map(t_map *mapbox, char *map_path)
{
	int		fd;
	int		h;
	char	*buffer;

	fd = open_map(map_path);
	h = -1;
	mapbox->map = (char **)malloc(sizeof(char) * mapbox->height);
	if (mapbox->map == NULL)
		exit_program();
	while (++h < mapbox->height)
	{
		buffer = get_next_line(fd);
		mapbox->map[h] = ft_strdup(buffer);
		if (mapbox->map[h] == NULL)
			exit_program();
	}
}

void	check_mapname(char *map_name)
{
	
}