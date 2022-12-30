/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/30 16:30:42 by nmota-bu         ###   ########.fr       */
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

void static load_img(t_game *game, char *name, int num, int type)
{
	int i;
	int w;
	int h;

	i = -1;
	while (++i < num)
	{
		char *path = path_img(name, i);
		if (type == 0)
			game->images.gwall[i] = mlx_xpm_file_to_image(game->grafic.mlx,
														  path, &w, &h);
		else if (type == 1)
			game->images.floor[i] = mlx_xpm_file_to_image(game->grafic.mlx,
														  path, &w, &h);
		else if (type == 2)
			game->images.wall[i] = mlx_xpm_file_to_image(game->grafic.mlx,
														 path, &w, &h);
		else if (type == 3)
			game->images.hero[i] = mlx_xpm_file_to_image(game->grafic.mlx,
														 path, &w, &h);
		else if (type == 4)
			game->images.door[i] = mlx_xpm_file_to_image(game->grafic.mlx,
														 path, &w, &h);
		else if (type == 5)
			game->images.logo[i] = mlx_xpm_file_to_image(game->grafic.mlx,
														 path, &w, &h);
		else if (type == 6)
			game->images.header[i] = mlx_xpm_file_to_image(game->grafic.mlx,
														   path, &w, &h);
		free(path);
	}
}

void init_img(t_game *game)
{
	load_img(game, "gwall", 8, GWALL);
	load_img(game, "floor", 1, FLOOR);
	load_img(game, "wall", 8, WALL);
	load_img(game, "frog", 4, HERO);
	load_img(game, "door", 2, DOOR);
	load_img(game, "logo", 1, LOGO);
	load_img(game, "header", 3, IHEADER);
}
