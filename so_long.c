/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:59:04 by shikim            #+#    #+#             */
/*   Updated: 2023/06/21 15:41:03 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_program(void)
{
	ft_printf("Good bye! see you later!\n");
	exit(0);
	return (0);
}

t_map	*parse_map(char *map_name)
{
	t_map	*mapbox;
	char	*map_path;

	check_mapname(map_name);
	mapbox = (t_map *)malloc(sizeof(t_map));
	if (mapbox == NULL)
		exit_program();
	map_path = ft_strjoin("./maps/", map_name);
	if (map_path == NULL)
		exit_program();
	set_mapbox_size(mapbox, map_path);
	set_mapbox_map(mapbox, map_path);
	set_mapbox_point(mapbox);
	free(map_path);
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
	t_all		all;
	t_map		*mapbox;
	t_graphic	graphic;
	t_imgbox	imgbox;
	t_position	player_position;

	if (ac == 2)
	{
		mapbox = parse_map(ag[1]);
		check_map(mapbox);
		graphic.mlx = mlx_init();
		graphic.win = mlx_new_window(graphic.mlx, mapbox->width * 64, \
			mapbox->height * 64, "SO_LONG..!");
		make_images(&imgbox, &graphic);
		make_all(&all, mapbox, &imgbox, &player_position);
		all.graphic = &graphic;
		render_init(&all);
		mlx_key_hook(graphic.win, &key_hook, &all);
		mlx_hook(graphic.win, 17, 0, &close_program, NULL);
		mlx_loop(graphic.mlx);
	}
	else
		ft_printf("Error! require one map file.\n");
	return (0);
}
