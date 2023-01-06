/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/06 23:59:17 by nmota-bu         ###   ########.fr       */
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

// void static moved(int move, int *px, int *py)
// {
// 	if (move == RIGHT)
// 		*py += 1;
// 	else if (move == LEFT)
// 		*py -= 1;
// 	else if (move == DOWN)
// 		*px += 1;
// 	else if (move == UP)
// 		*px -= 1;
// }

// void static loop_mom(t_game *game)
// {
// 	int px;
// 	int py;
// 	int move;

// 	px = game->map.objets.enemy.x;
// 	py = game->map.objets.enemy.y;
// 	move = rand() % 4;

// 	system("clear");
// 	for (int i = 0; i < game->map.rows; i++)
// 	{
// 		for (int j = 0; j < game->map.cols; j++)
// 		{
// 			printf("%c", game->map.map[i][j]);
// 		}
// 		printf("\n");
// 	}

// 	moved(move, &px, &py);
// 	if (game->map.map[px][py] != '1' && game->map.map[px][py] != 'E' && game->map.map[px][py] != 'C')
// 	{
// 		// esto para floor
// 		game->map.map[game->map.objets.enemy.x][game->map.objets.enemy.y] = '0';
// 		put_floor(game, game->map.objets.enemy.y, game->map.objets.enemy.x);

// 		// esto para mom
// 		game->map.map[px][py] = 'X';
// 		put_mom(game, py, px);
// 		game->map.objets.enemy.x = px;
// 		game->map.objets.enemy.y = py;
// 		game->key = TRUE;
// 	}
// 		else
// 		{
// 			px = game->map.objets.enemy.x;
// 			py = game->map.objets.enemy.y;
// 		}
// }

void print_map(t_game *game)
{
	system("clear");
	for (int i = 0; i < game->map.rows; i++)
	{
		for (int j = 0; j < game->map.cols; j++)
		{
			ft_printf("%c", game->map.map[i][j]);
		}
		ft_printf("\n");
	}
}

int static is_ok(char ch)
{
	if (ch == '0' || ch == 'C')
		return (1);
	else
		return (0);
}

void loop_mom(t_game *game)
{
	int row_diff;
	int col_diff;
	int pre_x;
	int pre_y;

	print_map(game);
	pre_x = game->map.objets.enemy.x;
	pre_y = game->map.objets.enemy.y;
	row_diff = game->map.objets.player.x - game->map.objets.enemy.x;
	col_diff = game->map.objets.player.y - game->map.objets.enemy.y;

	if (ft_abs(row_diff) > ft_abs(col_diff))
	{
		// Si P está más lejos en la columna, se mueve en la fila
		if (row_diff > 0)
		{
			// Si P está debajo de X, X se mueve hacia abajo
			if (is_ok(game->map.map[pre_x + 1][pre_y]))
				game->map.objets.enemy.x++;
		}
		else
		{
			// Si P está arriba de X, X se mueve hacia arriba
			if (is_ok(game->map.map[pre_x - 1][pre_y]))
				game->map.objets.enemy.x--;
		}
	}
	else
	{
		// Si P está más lejos en la fila, se mueve en la columna
		if (col_diff > 0)
		{
			// Si P está a la derecha de X, X se mueve hacia la derecha
			if (is_ok(game->map.map[pre_x][pre_y + 1]))
				game->map.objets.enemy.y++;
		}
		else
		{
			// Si P está a la izquierda de X, X se mueve hacia la izquierda
			if (is_ok(game->map.map[pre_x][pre_y - 1]))
				game->map.objets.enemy.y--;
		}
	}

	if (game->map.map[game->map.objets.enemy.x][game->map.objets.enemy.y] == 'C')
	{
		put_img(game, game->images.logo[0], pre_y, pre_x);
		game->map.map[pre_x][pre_y] = 'C';
	}
	else
	{
		put_floor(game, pre_y, pre_x);
		game->map.map[pre_x][pre_y] = '0';
	}

	// Actualiza la posición de X en el arreglo
	game->map.map[game->map.objets.enemy.x][game->map.objets.enemy.y] = 'X';
	put_img(game, game->images.mom[0], game->map.objets.enemy.y, game->map.objets.enemy.x);
	// put_mom(game, game->map.objets.enemy.y, game->map.objets.enemy.x);

	game->key = TRUE;
}

void loops(t_game *game)
{
		if (game->key)
			loop_hero(game);
		else if (!game->key)
			loop_mom(game);
}
