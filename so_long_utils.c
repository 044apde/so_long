/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:08:14 by shikim            #+#    #+#             */
/*   Updated: 2023/06/04 15:16:21 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_hook(int exit_value)
{
	write(1, "EXIT PROGRAM\n", 13);
	exit(exit_value);
}

int	my_key_hook(int keycode)
{
	if (keycode == 53)
		exit_hook(0);
	return (0);
}
