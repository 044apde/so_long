/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:59:04 by shikim            #+#    #+#             */
/*   Updated: 2023/06/12 15:58:01 by shikim           ###   ########.fr       */
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
	int			fd;
	t_map		*mapbox;
	t_graphic	graphic;
	t_image		*img;

	if (ac == 2)
	{
		mapbox = parse_map(ag[1]);
		check_map(mapbox);
		graphic.mlx = mlx_init();
		graphic.win = mlx_new_window(graphic.mlx, 1280, 1280, "SO_LONG..!");
		
		// 이미지 렌더링 테스트
		img = (t_image *)malloc(sizeof(t_image) * 1);
		img->path = "assets/background.xpm";
		img->w = 64;
		img->h = 64;
		img->img = mlx_xpm_file_to_image(graphic.mlx, img->path, &img->w, &img->h);
		mlx_put_image_to_window(graphic.mlx, graphic.win, img->img, 0, 0);

		// 이미지 렌더링 루프
		mlx_loop(graphic.mlx);
	}
	else
		ft_printf("Error! require one map file.\n");
	return (0);
}
