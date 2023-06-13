/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:18:37 by shikim            #+#    #+#             */
/*   Updated: 2023/06/13 18:48:27 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(void)
{
	ft_printf("Good bye so long... ;)\n");
	exit(0);
}

void	move_render(t_graphic *graphic, t_imgbox *imgbox)
{
	if (graphic)
		;
	if (imgbox)
		;
}

void	move_wasd(int keycode)
{
	if (keycode == 0)
		ft_printf("LEFT\n");
	if (keycode == 1)
		ft_printf("UP\n");
	if (keycode == 13)
		ft_printf("RIGHT\n");
	if (keycode == 2)
		ft_printf("DOWN\n");
}

int	key_hook(int keycode, t_graphic *graphic)
{
	if (graphic)
		;
	if (keycode == 53)
		exit_game();
	else if (keycode == 0 || keycode == 1 || keycode == 13 || keycode == 2)
		move_wasd(keycode);
	return (0);
}
