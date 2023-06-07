/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:08:14 by shikim            #+#    #+#             */
/*   Updated: 2023/06/07 11:33:01 by shikim           ###   ########.fr       */
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

size_t	ft_maplen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != 0 && s[length] != '\n')
		++length;
	return (length);
}

int	open_map(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error! fail to open map_file.\n");
		exit(1);
	}
	return (fd);
}

void	exit_program(void)
{
	ft_printf("Error! fail to malloc.\n");
	exit(1);
}
