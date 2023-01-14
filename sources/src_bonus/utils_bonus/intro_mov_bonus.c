/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_mov_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:09:35 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/14 00:29:49 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../../mlx/mlx.h"

void static loop_intro(t_game *game)
{
	int static i = 0;
	int static frame = 0;
	if (!(frame % 300))
	{

		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->images.intro[i], 0, 0);
		if (i == 148)
			star_game(game);
		// i = 0;
		i++;
		frame = 1;
	}
	else
		frame++;
}

void intro(t_game *game)
{
	game->grafic.win = mlx_new_window(game->grafic.mlx, 854, 480, "42 Barcelona");

	load_img_two(game, "intro", 149, INTRO);

	mlx_loop_hook(game->grafic.mlx, (void *)loop_intro, game);
	mlx_hook(game->grafic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
	mlx_hook(game->grafic.win, ON_KEYPRESS, 1L << 0, (void *)simple_key, game);
}
