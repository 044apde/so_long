/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:18:37 by shikim            #+#    #+#             */
/*   Updated: 2023/06/16 21:44:34 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(void)
{
	ft_printf("Good bye so long... ;)\n");
	exit(0);
}

void	move_player(t_all *all)
{
	void	*win;
	void	*mlx;
	void	*player;
	int		x;
	int		y;

	win = all->graphic->win;
	mlx = all->graphic->mlx;
	player = all->imgbox->img_player->img;
	x = all->player_position->x;
	y = all->player_position->y;
	mlx_put_image_to_window(mlx, win, all->imgbox->img_background->img, \
		all->player_position->old_x * 64, all->player_position->old_y * 64);
	mlx_put_image_to_window(mlx, win, player, x * 64, y * 64);
	if (all->mapbox->map[y][x] == 'C')
		all->mapbox->flag_c--;
	if (all->mapbox->map[y][x] == 'E')
	{
		if (all->mapbox->flag_c == 0)
			ft_printf("You win! you have moved :%d\n", all->mapbox->count_move);
		else
			ft_printf("You lose! collect all collectible..\n");
		exit(0);
	}
}

void	detect_move(int keycode, t_all *all)
{
	int		new_x;
	int		new_y;
	char	**map;

	new_x = all->player_position->x;
	new_y = all->player_position->y;
	map = all->mapbox->map;
	if (keycode == 0)
		new_x = all->player_position->x - 1;
	else if (keycode == 13)
		new_y = all->player_position->y - 1;
	else if (keycode == 2)
		new_x = all->player_position->x + 1;
	else if (keycode == 1)
		new_y = all->player_position->y + 1;
	if (new_x <= 0 || new_x >= all->mapbox->width || new_y <= 0 \
		|| new_y >= all->mapbox->height || map[new_y][new_x] == '1' \
			|| map[new_y][new_x] == '1')
		return ;
	all->player_position->x = new_x;
	all->player_position->y = new_y;
	all->mapbox->count_move++;
	ft_printf("move count: %d\n", all->mapbox->count_move);
	move_player(all);
}

int	key_hook(int keycode, t_all *all)
{
	t_graphic	*graphic;
	t_imgbox	*imgbox;
	t_map		*mapbox;
	t_position	*player_position;

	graphic = all->graphic;
	imgbox = all->imgbox;
	mapbox = all->mapbox;
	player_position = all->player_position;
	all->player_position->old_x = all->player_position->x;
	all->player_position->old_y = all->player_position->y;
	if (keycode == 53)
		exit_game();
	else if (keycode == 0 || keycode == 1 || keycode == 13 || keycode == 2)
		detect_move(keycode, all);
	return (0);
}
