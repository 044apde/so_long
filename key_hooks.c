/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:18:37 by shikim            #+#    #+#             */
/*   Updated: 2023/06/13 22:55:55 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(void)
{
	ft_printf("Good bye so long... ;)\n");
	exit(0);
}

void	move_player(t_graphic *graphic, t_imgbox *imgbox, t_map *mapbox)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = graphic->mlx;
	win = graphic->win;
	x = 0;
	y = 0;
	ft_printf("%p %p %p %p\n", mlx, win, imgbox, imgbox->img_background->img);
}

void	move_wasd(int keycode, t_graphic *graphic, t_imgbox *imgbox, t_map *mapbox)
{
	if (keycode == 0)
		ft_printf("LEFT\n");
	if (keycode == 1)
		ft_printf("UP\n");
	if (keycode == 13)
		ft_printf("RIGHT\n");
	if (keycode == 2)
		ft_printf("DOWN\n");
	move_player(graphic, imgbox, mapbox);
}

int	key_hook(int keycode, t_all *all)
{
	t_graphic 	*graphic;
	t_imgbox	*imgbox;
	t_map		*mapbox;

	graphic = all->graphic;
	imgbox = all->imgbox;
	mapbox = all->mapbox;
	if (keycode == 53)
		exit_game();
	else if (keycode == 0 || keycode == 1 || keycode == 13 || keycode == 2)
		move_wasd(keycode, graphic, imgbox, mapbox);
	return (0);
}