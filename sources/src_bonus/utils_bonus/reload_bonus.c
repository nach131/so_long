/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/07 14:13:25 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../../mlx/mlx.h"

void static put_hero_loop(t_game *game, char *img)
{
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							img,
							game->map.objets.player.y * SQUARE,
							game->map.objets.player.x * SQUARE + HEADER);
}

void static loop_hero(t_game *game)
{
	int static i = 0;
	int static frame = 0;

	if (!(frame % 600))
	{
		if (game->dir.right)
			put_hero_loop(game, game->images.hero_r[i]);
		else if (game->dir.left)
			put_hero_loop(game, game->images.hero_l[i]);
		else if (game->dir.down)
			put_hero_loop(game, game->images.hero_d[i]);
		else if (game->dir.up)
			put_hero_loop(game, game->images.hero_u[i]);
		if (i == 7)
		{
			i = 0;
			game->key = FALSE;
		}
		i++;
		frame = 1;
	}
	else
		frame++;
}

void loops(t_game *game)
{
		if (game->key)
			loop_hero(game);
		else if (!game->key)
			loop_mom(game);
}
