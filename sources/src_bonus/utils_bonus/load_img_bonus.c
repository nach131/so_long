/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/13 23:48:14 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../../mlx/mlx.h"

char static *path_img(char *name_img, int n)
{
	char *nbr;
	char *s1;
	char *s2;

	nbr = ft_itoa(n);
	s1 = ft_strjoin("xpm/", name_img);
	s2 = ft_strjoin(s1, "/");
	free(s1);
	s1 = ft_strjoin(s2, name_img);
	free(s2);
	s2 = ft_strjoin(s1, nbr);
	free(s1);
	s1 = ft_strjoin(s2, ".xpm");
	free(s2);
	free(nbr);
	return (s1);
}

void static load_img_one(t_game *game, char *name, int num, int type)
{
	int i;
	int w;
	int h;
	void *mlx = game->grafic.mlx;
	char *path;

	i = -1;
	while (++i < num)
	{
		path = path_img(name, i);
		if (type == GWALL)
			game->images.gwall[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == FLOOR)
			game->images.floor[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == WALL)
			game->images.wall[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == DOOR)
			game->images.door[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == LOGO)
			game->images.logo[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == IHEADER)
			game->images.header[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == MOM)
			game->images.mom[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		free(path);
	}
}
void load_img_two(t_game *game, char *name, int num, int type)
{
	int i;
	int w;
	int h;
	void *mlx = game->grafic.mlx;
	char *path;

	i = -1;
	while (++i < num)
	{
		path = path_img(name, i);
		if (type == HERO_L)
			game->images.hero_l[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == HERO_R)
			game->images.hero_r[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == HERO_D)
			game->images.hero_d[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == HERO_U)
			game->images.hero_u[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == HERO_G)
			game->images.hero_g[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == END_ANI)
			game->images.endgame[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		else if (type == INTRO)
			game->images.intro[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		free(path);
	}
}

void init_img(t_game *game)
{
	load_img_one(game, "gwall", 8, GWALL);
	load_img_one(game, "floor", 1, FLOOR);
	load_img_one(game, "wall", 8, WALL);
	load_img_one(game, "door", 4, DOOR);
	load_img_one(game, "logo", 39, LOGO);
	load_img_one(game, "header", 4, IHEADER);
	load_img_one(game, "mom_h", 4, MOM);
	load_img_two(game, "rabbit_l", 8, HERO_L);
	load_img_two(game, "rabbit_r", 8, HERO_R);
	load_img_two(game, "rabbit_d", 8, HERO_D);
	load_img_two(game, "rabbit_u", 8, HERO_U);
	load_img_two(game, "rabbit_g", 5, HERO_G);
}
