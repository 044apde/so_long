/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:13:23 by shikim            #+#    #+#             */
/*   Updated: 2023/06/15 23:01:51 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_hook(int mousecode, int x, int y, t_all *all)
{
	ft_printf("%d\n", mousecode);
	ft_printf("%p\n", all->mapbox);
	mlx_mouse_get_pos(all->graphic->win, &x, &y);
	ft_printf("%d %d\n", x, y);
	if (all->graphic->win == NULL)
		ft_printf("exit\n");
	return (0);
}
