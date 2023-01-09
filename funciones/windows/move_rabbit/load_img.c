/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:17:39 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/09 17:33:57 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "header.h"

// void load_images(t_game *game)
// {
// 	int width;
// 	int height;

// 	game->textures[ROCKS] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/gwall/gwall0.xpm", &width, &height);
// 	game->textures[TGREEN] = mlx_xpm_file_to_image(game->mlx, "../xpm/tree_GREEN.xpm", &width, &height);
// 	game->textures[GRASS] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/floor/floor0.xpm", &width, &height);
// 	game->textures[DOORC] = mlx_xpm_file_to_image(game->mlx, "../xpm/door_closed.xpm", &width, &height);
// 	game->textures[ROJO] = mlx_xpm_file_to_image(game->mlx, "../xpm/rojo.xpm", &width, &height);
// }

char static *path_img(char *name_img, int n)
{
	char *nbr;
	char *s1;
	char *s2;

	nbr = ft_itoa(n);
	s1 = ft_strjoin("../../../sources/xpm/", name_img);
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

void load_img(t_game *game, char *name, int num, int type)
{
	int i;
	int w;
	int h;
	char *path;
	t_list *tmp;
	tmp = NULL;

	i = -1;

	while (++i < num)
	{
		path = path_img(name, i);
		if (type == HERO)
			game->hero[i] = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
		else if (type == LOGO)
			game->logo[i] = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
		else if (type == MOM)
		{
			tmp = ft_lstnew(mlx_xpm_file_to_image(game->mlx, path, &w, &h));
			game->mom = tmp;
		}
	}
}
