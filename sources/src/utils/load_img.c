/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/11 00:31:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "../../mlx/mlx.h"

char static	*path_img(char *name_img, int n)
{
	char	*nbr;
	char	*s1;
	char	*s2;

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

void	load_img(t_game *game, char *name, int num, int type)
{
	int		i;
	int		w;
	int		h;
	void	*mlx;
	char	*path;

	mlx = game->graphic.mlx;
	i = -1;
	while (++i < num)
	{
		path = path_img(name, i);
		if (type == HERO)
			game->images.hero[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		free(path);
	}
}

void static	load_img_two(t_game *game, char *name, int num, int type)
{
	int		i;
	int		w;
	int		h;
	void	*mlx;
	char	*path;

	mlx = game->graphic.mlx;
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
		free(path);
	}
}

void	init_img(t_game *game)
{
	load_img_two(game, "gwall", 8, GWALL);
	load_img_two(game, "floor", 1, FLOOR);
	load_img_two(game, "wall", 8, WALL);
	load_img_two(game, "door", 4, DOOR);
	load_img_two(game, "logo", 1, LOGO);
	load_img_two(game, "header", 3, IHEADER);
}
