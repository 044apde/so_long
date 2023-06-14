/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:18:37 by shikim            #+#    #+#             */
/*   Updated: 2023/06/14 22:07:13 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(void)
{
	ft_printf("Good bye so long... ;)\n");
	exit(0);
}

void	move_player(void)
{

}

void	detect_move(int keycode, t_imgbox *imgbox, t_map *mapbox, \
	t_position *player_position)
{
	int		new_x;
	int		new_y;
	char	**map;

	new_x = player_position->x;
	new_y = player_position->y;
	map = mapbox->map;
	if (keycode == 0)
		new_x = player_position->x - 1;
	else if (keycode == 13)
		new_y = player_position->y - 1;
	else if (keycode == 2)
		new_x = player_position->x + 1;
	else if (keycode == 1)
		new_y = player_position->y + 1;
	if (new_x <= 0 || new_x >= mapbox->width - 1 || new_y <= 0 \
		|| new_y >= mapbox->height - 1 || map[new_y][new_x] == '1' \
			|| map[new_y][new_x] == '1')
		return ;
	else
		player_position->x = new_x;
		player_position->y = new_y;
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
	if (keycode == 53)
		exit_game();
	else if (keycode == 0 || keycode == 1 || keycode == 13 || keycode == 2)
		detect_move(keycode, imgbox, mapbox, player_position);
	return (0);
}
