/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:59:04 by shikim            #+#    #+#             */
/*   Updated: 2023/06/05 17:55:56 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	make_background(t_graphic win, void *img_file)
{
	int	i;
	int	j;

	i = 0;
	while (i < 640 / 8)
	{
		j = 0;
		while (j < 480 / 8)
		{
			mlx_put_image_to_window(win.mlx, win.win, img_file, i * 8, j * 8);
			j++;
		}
		i++;
	}
	return (0);
}

void	*make_image(t_graphic win, char *r_path)
{
	t_image	*img_ptr;
	void	*img_file;

	img_ptr = (t_image *)malloc(sizeof(t_image));
	img_ptr->relative_path = r_path;
	img_ptr->img = mlx_xpm_file_to_image(win.mlx, BACKGROUND, &img_ptr->w, &img_ptr->h);
	return (img_ptr->img);
}

int	check_map(void)
{
	return (0);
}

int	make_map(void)
{
	return (0);
}

int	main(int ac, char **av)
{
	t_graphic	graphic;
	void		*background_img;
	
	graphic.mlx = mlx_init();
	graphic.win = mlx_new_window(graphic.mlx, 640, 480, "SO_LONG");
	background_img = make_image(graphic, "grass.png");
	make_background(graphic, background_img);
	mlx_key_hook(graphic.win, my_key_hook, &graphic);
	mlx_loop(graphic.mlx);
	return (0);
}
