/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:59:04 by shikim            #+#    #+#             */
/*   Updated: 2023/06/06 18:28:47 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error! fail to open map_file.\n");
		exit(1);
	}
	return (fd);
}

void set_map_info(t_map *map_info, char *map_path)
{
	int	fd;
	
	fd = open_map(map_path);
}

t_map	*make_map(char *map_name)
{
	t_map	*map_info;
	char	*map_path;

	map_info = (t_map *)malloc(sizeof(t_map));
	map_path = ft_strjoin("./assets/maps/", map_name);
	set_map_info(map_info, map_path);
	return (map_info);
}

int	main(int ac, char **ag)
{
	int		fd;
	char	*map_file;
	
	if (ac == 2)
	{
		make_map(ag[1]);
	}
	else
		ft_printf("Error! require one map file.\n");
	return (0);
}
