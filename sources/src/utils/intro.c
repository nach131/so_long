/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/15 02:24:55 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "../../mlx/mlx.h"

void intro_key(int key, t_game *game)
{
	(void)game;
	if (key == 53)
		exit(0);
	else if (key == KEY_ONE)
		load_img(game, "rabbit", 4, HERO);
	else if (key == KEY_TWO)
		load_img(game, "frog", 4, HERO);
	star_game(game);
}

void intro(t_game *game)
{
	int w;
	int h;
	char *img;

	game->grafic.win = mlx_new_window(game->grafic.mlx, 608, 321, "choose your hero");
	img = mlx_xpm_file_to_image(game->grafic.mlx, "xpm/choose/choose.xpm", &w, &h);
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, img, 0, 0);
	mlx_key_hook(game->grafic.win, (void *)intro_key, game);
}
