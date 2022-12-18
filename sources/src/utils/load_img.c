/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/18 00:27:37 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
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

// void static load_img(void *mlx, t_images *img)
// {
// 	int w;
// 	int h;
// 	char *path = path_img("gwall", TORANGE);

// 	img->gwall[TORANGE] = mlx_xpm_file_to_image(mlx, path, &w, &h);

// 	free(path);
// }

void static load_img(t_game *game, char *name, int num, int type)
{
	int i = -1;
	int w;
	int h;
	while (++i < num)
	{
		char *path = path_img(name, i);
		if (type == 0)
			game->images.gwall[i] = mlx_xpm_file_to_image(game->grafic.mlx,
														  path, &w, &h);
		else if (type == 1)
			game->images.floor[i] = mlx_xpm_file_to_image(game->grafic.mlx,
														  path, &w, &h);
		free(path);
	}
}

void init_img(t_game *game)
{
	ft_printf("%s\n", path_img("gwall", 1));
	// load_img(mlx, img);

	load_img(game, "gwall", 6, GWALL);
	load_img(game, "floor", 7, FLOOR);
}
