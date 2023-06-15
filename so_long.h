/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:02:29 by shikim            #+#    #+#             */
/*   Updated: 2023/06/15 23:03:04 by shikim           ###   ########.fr       */
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
# define FALSE 0
# define MAX 1200

typedef struct s_win_pack {
	void	*mlx;
	void	*win;
}		t_graphic;

typedef struct s_img_pack {
	void	*img;
	char	*path;
	int		w;
	int		h;
}	t_image;

typedef struct s_map_coordinate {
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_player_position {
	int	x;
	int	old_x;
	int	y;
	int	old_y;
}	t_position;

typedef struct s_circle_queue {
	t_position	p_position[MAX];
	int			front;
	int			rear;
}	t_cqueue;

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
	int				count_move;
	char			**map;
	char			**visited;
}	t_map;

typedef struct s_img_box {
	t_image	*img_background;
	t_image	*img_player;
	t_image	*img_wall;
	t_image	*img_collectible;
	t_image	*img_exit;
}	t_imgbox;

typedef struct s_all {
	t_imgbox	*imgbox;
	t_graphic	*graphic;
	t_map		*mapbox;
	t_position	*player_position;
}	t_all;

void		exit_program(void);
void		check_component(t_map *mapbox);
void		set_map_length(t_map *mapbox, char *map_path);
void		set_mapbox_size(t_map *mapbox, char *map_path);
void		set_mapbox_map(t_map *mapbox, char *map_path);
void		set_mapbox_point(t_map *mapbox);
void		check_map_surround(t_map *mapbox);
void		check_reptition(t_map *mapbox);
void		check_mapname(char *map_name);
void		init_cqueue(t_cqueue *queue, t_map *mapbox);
void		enqueue(t_cqueue *queue, int x, int y, t_map *mapbox);
int			check_path(t_map *mapbox);
int			open_map(char *map_path);
int			is_full(t_cqueue *queue);
int			is_empty(t_cqueue *queue);
int			ft_maplen(const char *s);
t_position	*dequeue(t_cqueue *queue);
void		alloacte_imgs(t_imgbox *imgbox);
void		choose_path(t_imgbox *imgbox);
void		set_width_height(t_imgbox *imgbox);
void		make_img_from_xpm(t_imgbox *imgbox, t_graphic *graphic);
void		make_images(t_imgbox *imgbox, t_graphic *graphic);
int			key_hook(int keycode, t_all *all);
void		detect_move(int keycode, t_all *all);
void		exit_game(void);
void		make_all(t_all *all, t_map *mapbox, t_imgbox *imgbox, \
	t_position *player_position);
void		render_init(t_all *all);
int			mouse_hook(int mousecode, int x, int y, t_all *all);

#endif
