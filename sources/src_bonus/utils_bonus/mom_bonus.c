/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mom_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:11:27 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/15 16:35:59 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../mlx/mlx.h"

// void print_map(t_game *game)
// {
// 	system("clear");
// 	for (int i = 0; i < game->map.rows; i++)
// 	{
// 		for (int j = 0; j < game->map.cols; j++)
// 		{
// 			ft_printf("%c", game->map.map[i][j]);
// 		}
// 		ft_printf("\n");
// 	}
// }

int static	is_ok(char ch)
{
	if (ch == '0' || ch == 'C')
		return (1);
	else
		return (0);
}

void static	major_row(t_game *game, int row_diff, int pre_x, int pre_y)
{
	if (row_diff > 0)
	{
		if (is_ok(game->map.map[pre_x + 1][pre_y]))
			game->map.objets.enemy.x++;
	}
	else
	{
		if (is_ok(game->map.map[pre_x - 1][pre_y]))
			game->map.objets.enemy.x--;
	}
}

void static	major_col(t_game *game, int col_diff, int pre_x, int pre_y)
{
	if (col_diff > 0)
	{
		if (is_ok(game->map.map[pre_x][pre_y + 1]))
			game->map.objets.enemy.y++;
	}
	else
	{
		if (is_ok(game->map.map[pre_x][pre_y - 1]))
			game->map.objets.enemy.y--;
	}
}

void static	reload_stepped(t_game *game, int pre_x, int pre_y)
{
	if (game->map.map[game->map.objets.enemy.x]
		[game->map.objets.enemy.y] == 'C')
	{
		put_img(game, game->images.logo[0], pre_y, pre_x);
		game->map.map[pre_x][pre_y] = 'C';
	}
	else
	{
		put_img(game, game->images.floor[0], pre_y, pre_x);
		game->map.map[pre_x][pre_y] = '0';
	}
}

void	loop_mom(t_game *game)
{
	int	row_diff;
	int	col_diff;
	int	pre_x;
	int	pre_y;

	pre_x = game->map.objets.enemy.x;
	pre_y = game->map.objets.enemy.y;
	row_diff = game->map.objets.player.x - game->map.objets.enemy.x;
	col_diff = game->map.objets.player.y - game->map.objets.enemy.y;
	if (ft_abs(row_diff) > ft_abs(col_diff))
		major_row(game, row_diff, pre_x, pre_y);
	else
		major_col(game, col_diff, pre_x, pre_y);
	reload_stepped(game, pre_x, pre_y);
	caught(game);
	game->map.map[game->map.objets.enemy.x][game->map.objets.enemy.y] = 'X';
	put_mom(game);
	game->key = TRUE;
}
