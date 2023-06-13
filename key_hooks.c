/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:18:37 by shikim            #+#    #+#             */
/*   Updated: 2023/06/13 14:12:38 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(void)
{
	ft_printf("Good bye so long...\n");
	exit(1);
}

void	move_wasd(int keycode)
{
	ft_printf("Move to %d\n", keycode);
}

int	key_hook(int keycode, t_graphic *vars)
{
	if (keycode == 53)
		exit_game();
	else if (keycode == 0 || keycode == 1 || keycode == 13 || keycode == 2)
		move_wasd(keycode);
	return (0);
}
