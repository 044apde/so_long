/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:02:29 by shikim            #+#    #+#             */
/*   Updated: 2023/06/07 21:28:20 by shikim           ###   ########.fr       */
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
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# define TRUE 1
# define BG "grass.xpm"

typedef struct s_win_pack {
	void	*mlx;
	void	*win;
}		t_graphic;

typedef struct s_img_pack {
	void	*img;
	char	*relative_path;
	int		w;
	int		h;
}	t_image;

typedef struct s_map_coordinate {
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_player_position {
	int	x;
	int	y;
} t_position;

typedef struct s_queue {
	t_position	**p_position;
	int			front;
	int			rear;
} t_queue;

typedef struct s_map_box {
	int				width;
	int				height;
	int				flag_e;
	int				flag_p;
	int				flag_c;
	int				p_x;
	int				p_y;
	int				e_x;
	int				e_y;
	char			**map;
}	t_map;

void	exit_program(void);
void	exit_hook(int exit_value);
void	check_component(t_map *mapbox);
void	set_map_length(t_map *mapbox, char *map_path);
void	set_mapbox_size(t_map *mapbox, char *map_path);
void	set_mapbox_map(t_map *mapbox, char *map_path);
void	set_mapbox_point(t_map *mapbox);
void	check_map_surround(t_map *mapbox);
void	check_reptition(t_map *mapbox);
void	check_mapname(char *map_name);
void	find_path(t_map *mapbox);
int		my_key_hook(int keycode);
int		open_map(char *map_path);
size_t	ft_maplen(const char *s);

#endif
