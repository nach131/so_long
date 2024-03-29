/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:40:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/11 00:31:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"

void	locate(t_game *game, int x, int y, char ch)
{
	if (ch == 'P')
	{
		game->map.objets.player.x = x;
		game->map.objets.player.y = y;
	}
	else if (ch == 'E')
	{
		game->map.objets.exit.x = x;
		game->map.objets.exit.y = y;
	}
	else if (ch == 'X')
	{
		game->map.objets.enemy.x = x;
		game->map.objets.enemy.y = y;
	}
}

void	put_player(t_game *game, int type)
{
	put_img(game, game->images.floor[0], game->map.objets.player.y,
		game->map.objets.player.x);
	if (type == RIGHT)
		game->map.objets.player.y += 1;
	else if (type == LEFT)
		game->map.objets.player.y -= 1;
	else if (type == DOWN)
		game->map.objets.player.x += 1;
	else if (type == UP)
		game->map.objets.player.x -= 1;
}

void	open_door(t_game *game)
{
	int	frame;
	int	i;

	frame = 0;
	i = 0;
	while (i < 4)
	{
		while (TRUE)
		{
			if (!(frame % 1000))
			{
				mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
					game->images.door[i], game->map.objets.exit.y * SQUARE,
					game->map.objets.exit.x * SQUARE + HEADER);
				break ;
			}
			else
				frame++;
		}
		i++;
		frame = 1;
	}
}

void static	ctrl_dir(t_dir *dir, int type)
{
	if (type == RIGHT)
		dir->right = TRUE;
	else if (type == LEFT)
		dir->left = TRUE;
	else if (type == DOWN)
		dir->down = TRUE;
	else if (type == UP)
		dir->up = TRUE;
}

void	move(t_game *game, int x, int y, int type)
{
	ctrl_dir(&game->dir, type);
	if (game->map.map[x][y] == 'X')
		exit(0);
	if (game->map.map[x][y] == 'C')
		game->map.objets.get++;
	if (game->map.map[x][y] != '1' && game->map.map[x][y] != 'E' &&
		game->map.map[x][y] != 'X')
	{
		game->map.map[x][y] = 'P';
		put_player(game, type);
		ctrl_move(game);
	}
	if (game->map.objets.goals == game->map.objets.get)
		open_door(game);
	if (game->map.map[x][y] == 'E' &&
		(game->map.objets.get == game->map.objets.goals))
	{
		game->won = TRUE;
		endgame(game);
	}
}
