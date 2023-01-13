/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/12 16:34:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../../mlx/mlx.h"

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
			game->key = MOM_ANI;
		}
		i++;
		frame = 1;
	}
	else
		frame++;
}

void endgame(t_game *game)
{
	mlx_loop_hook(game->grafic.mlx, NULL, NULL);
	// sleep(2);
	ft_printf(RED "\tGAME-OVER \n");
}

void loops(t_game *game)
{
	if (!game->gameover)
	{
		if (game->key)
			loop_hero(game);
		else if (!game->key)
			loop_mom(game);
	}
	else
		thanos_loop(game);
	if (game->key == END_ANI)
		endgame(game);
}
