/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mom_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:35:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/05 13:55:10 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdlib.h>

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../mlx/mlx.h"

void mom_actio(t_game *game)
{
	int px;
	int py;
	int move;

	px = game->map.objets.enemy.x;
	py = game->map.objets.enemy.y;
	move = rand() % 4;

	system("clear");
	for (int i = 0; i < game->map.rows; i++)
	{
		for (int j = 0; j < game->map.cols; j++)
		{
			printf("%c", game->map.map[i][j]);
		}
		printf("\n");
	}
	if (move == RIGHT)
		py += 1;
	else if (move == LEFT)
		py -= 1;
	else if (move == DOWN)
		px += 1;
	else if (move == UP)
		px -= 1;
	if (game->map.map[px][py] != '1' && game->map.map[px][py] != 'E')
	{
		game->map.map[game->map.objets.enemy.x][game->map.objets.enemy.y] = '+';
		game->map.map[px][py] = 'X';
		game->map.objets.enemy.x = px;
		game->map.objets.enemy.y = py;
	}
	else
	{
		px = game->map.objets.enemy.x;
		py = game->map.objets.enemy.y;
	}
}

void mom(t_game *game)
{

	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							game->images.mom[3],
							game->map.objets.enemy.y * SQUARE,
							game->map.objets.enemy.x * SQUARE + HEADER);

	mlx_loop_hook(game->grafic.mlx, (void *)mom_actio, game);
	// mlx_expose_hook(game->grafic.mlx, (void *)mom_actio, game);
}
