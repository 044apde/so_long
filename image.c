/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:01:03 by shikim            #+#    #+#             */
/*   Updated: 2023/06/12 20:04:41 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloacte_imgs(t_imgbox *imgbox)
{
	imgbox->img_background= (t_image *)malloc(sizeof(t_image) * 1);
	imgbox->img_collectible = (t_image *)malloc(sizeof(t_image) * 1);
	imgbox->img_exit = (t_image *)malloc(sizeof(t_image) * 1);
	imgbox->img_player = (t_image *)malloc(sizeof(t_image) * 1);
	imgbox->img_wall = (t_image *)malloc(sizeof(t_image) * 1);
}

void	choose_path(t_imgbox *imgbox)
{
	imgbox->img_background->path = "assets/background.xpm";
	imgbox->img_collectible->path = "assets/collectible.xpm";
	imgbox->img_exit->path = "assets/exit.xpm";
	imgbox->img_player->path = "assets/player.xpm";
	imgbox->img_wall->path = "assets/wall.xpm";
}

void	set_width_height(t_imgbox *imgbox)
{
	imgbox->img_background->w = 64;
	imgbox->img_background->h = 64;
	imgbox->img_collectible->w = 64;
	imgbox->img_collectible->h = 64;
	imgbox->img_exit->w = 64;
	imgbox->img_exit->h = 64;
	imgbox->img_player->w = 64;
	imgbox->img_player->h = 64;
	imgbox->img_wall->w = 64;
	imgbox->img_wall->h = 64;
}

void	make_img_from_xpm(t_imgbox *imgbox, t_graphic *graphic)
{
	imgbox->img_background->img = mlx_xpm_file_to_image(graphic->mlx, imgbox->img_background->path, &imgbox->img_background->w, &imgbox->img_background->h);
	imgbox->img_collectible->img = mlx_xpm_file_to_image(graphic->mlx, imgbox->img_collectible->path, &imgbox->img_collectible->w, &imgbox->img_collectible->h);
	imgbox->img_exit->img = mlx_xpm_file_to_image(graphic->mlx, imgbox->img_exit->path, &imgbox->img_exit->w, &imgbox->img_exit->h);
	imgbox->img_player->img = mlx_xpm_file_to_image(graphic->mlx, imgbox->img_player->path, &imgbox->img_player->w, &imgbox->img_player->h);
	imgbox->img_wall->img = mlx_xpm_file_to_image(graphic->mlx, imgbox->img_wall->path, &imgbox->img_wall->w, &imgbox->img_wall->h);
}
