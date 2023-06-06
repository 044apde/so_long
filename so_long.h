/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:02:29 by shikim            #+#    #+#             */
/*   Updated: 2023/06/06 16:46:04 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
#include <errno.h>

# define TRUE 1
# define BG "grass.xpm"

typedef struct win_pack {
	void	*mlx;
	void	*win;
}		t_graphic;

typedef struct img_pack {
	void	*img;
	char	*relative_path;
	int		w;
	int		h;
}	t_image;

typedef struct map_info {
	int		width;
	int		height;
	char	*map;
}	t_map;

void	exit_hook(int exit_value);
int		my_key_hook(int keycode);
size_t	ft_maplen(const char *s);

#endif
