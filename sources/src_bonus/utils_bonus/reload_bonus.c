/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/05 20:21:50 by nmota-bu         ###   ########.fr       */
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

void static moved(int move, int *px, int *py)
{
	if (move == RIGHT)
		*py += 1;
	else if (move == LEFT)
		*py -= 1;
	else if (move == DOWN)
		*px += 1;
	else if (move == UP)
		*px -= 1;
}

void static loop_mom(t_game *game)
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

	moved(move, &px, &py);
	if (game->map.map[px][py] != '1' && game->map.map[px][py] != 'E' && game->map.map[px][py] != 'C')
	{
		// esto para floor
		game->map.map[game->map.objets.enemy.x][game->map.objets.enemy.y] = '+';
		put_floor(game, game->map.objets.enemy.y, game->map.objets.enemy.x);

		// esto para mom
		game->map.map[px][py] = 'X';
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.mom[0],
								py * SQUARE,
								px * SQUARE + HEADER);

		game->map.objets.enemy.x = px;
		game->map.objets.enemy.y = py;
		game->key = TRUE;
	}
		else
		{
			px = game->map.objets.enemy.x;
			py = game->map.objets.enemy.y;
		}
}

void loops(t_game *game)
{
		if (game->key)
			loop_hero(game);
		else if (!game->key)
			loop_mom(game);
}
