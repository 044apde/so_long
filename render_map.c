/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:41:24 by shikim            #+#    #+#             */
/*   Updated: 2023/06/15 17:25:59 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_all *all)
{
	void	*background;
	void	*mlx;
	void	*win;
	int		h;
	int		w;

	background = all->imgbox->img_background->img;
	mlx = all->graphic->mlx;
	win = all->graphic->win;
	h = -1;
	while (++h < all->mapbox->height)
	{
		w = -1;
		while (++w < all->mapbox->width)
			mlx_put_image_to_window(mlx, win, background, w * 64, h * 64);
	}
}

void	render_wall(t_all *all)
{
	int		h;
	int		w;
	char	**map;
	void	*mlx;
	void	*win;

	h = -1;
	map = all->mapbox->map;
	mlx = all->graphic->mlx;
	win = all->graphic->win;
	while (++h < all->mapbox->height)
	{
		w = -1;
		while (++w < all->mapbox->width)
			if (all->mapbox->map[h][w] == '1')
				mlx_put_image_to_window(mlx, win, all->imgbox->img_wall->img, \
					w * 64, h * 64);
	}
}

void	render_exit(t_all *all)
{
	t_map	*mapbox;
	void	*mlx;
	void	*win;
	void	*exit;

	mapbox = all->mapbox;
	mlx = all->graphic->mlx;
	win = all->graphic->win;
	exit = all->imgbox->img_exit->img;
	mlx_put_image_to_window(mlx, win, exit, mapbox->e_x * 64, mapbox->e_y * 64);
}