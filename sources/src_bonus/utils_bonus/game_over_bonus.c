/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:02:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/15 19:03:08 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../../mlx/mlx.h"

void	caught(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map.map;
	x = game->map.objets.enemy.x;
	y = game->map.objets.enemy.y;
	if (map[x][y + 1] == 'P' || map[x][y - 1] == 'P' || map[x + 1][y] == 'P'\
			|| map[x - 1][y] == 'P')
	{
		game->gameover = TRUE;
		game->key = FALSE;
	}
}

void	thanos_loop(t_game *game)
{
	int static	i = 0;
	int static	frame = 0;

	if (i <= 5)
	{
		if (!(frame % 1800))
		{
			put_hero_loop(game, game->images.hero_g[i]);
			i++;
			frame = 1;
		}
		else
			frame++;
	}
	if (i > 5)
		game->key = END_ANI;
}
