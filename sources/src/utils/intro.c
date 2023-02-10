/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
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

void	intro_key(int key, t_game *game)
{
	if (key == 53)
		exit(0);
	else if (key == KEY_ONE)
		load_img(game, "rabbit", 4, HERO);
	else if (key == KEY_TWO)
		load_img(game, "frog", 4, HERO);
	else if (key == KEY_THREE)
		load_img(game, "penguin", 4, HERO);
	else
		load_img(game, "pink", 4, HERO);
	star_game(game);
}

void	intro(t_game *game)
{
	int		w;
	int		h;
	char	*img;

	game->graphic.win = mlx_new_window(game->graphic.mlx, 608, 321,
			"choose your hero");
	img = mlx_xpm_file_to_image(game->graphic.mlx,
			"xpm/choose/choose.xpm", &w, &h);
	mlx_put_image_to_window(game->graphic.mlx, game->graphic.win, img, 0, 0);
	mlx_key_hook(game->graphic.win, (void *)intro_key, game);
	mlx_hook(game->graphic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
}
