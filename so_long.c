/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:59:04 by shikim            #+#    #+#             */
/*   Updated: 2023/06/07 10:38:27 by shikim           ###   ########.fr       */
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

t_map	*parse_map(char *map_name)
{
	t_map	*mapbox;
	char	*map_path;

	mapbox = (t_map *)malloc(sizeof(t_map));
	map_path = ft_strjoin("./assets/maps/", map_name);
	set_mapbox_size(mapbox, map_path);
	set_mapbox_map(mapbox, map_path);
	return (mapbox);
}

void	check_component(t_map *mapbox)
{
	int		h;
	int		w;
	char	*allowed_component;

	h = -1;
	allowed_component = "01CEP";
	while(++h < mapbox->height)
	{
		w = -1;
		while(++w < mapbox->width)
		{
			if(ft_strchr(allowed_component, mapbox->map[h][w]) == 0)
			{
				ft_printf("Error! map contains prohibited components.\n");
			}
		}
	}
}

void	check_map(t_map *mapbox)
{
	check_component(mapbox);
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
