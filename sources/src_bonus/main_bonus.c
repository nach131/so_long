/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/14 12:16:13 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../mlx/mlx.h"

int key_hook(int keycode, t_game *game)
{
	int x;
	int y;
	game->key = TRUE;
	x = game->map.objets.player.x;
	y = game->map.objets.player.y;
	ft_bzero(&game->dir, sizeof(t_dir));
	game->map.map[x][y] = '0';
	if (keycode == 53)
		exit(0);
	if (!game->gameover)
	{
		if (keycode == 2 || keycode == 124)
			move(game, x, y + 1, RIGHT);
		else if (keycode == 0 || keycode == 123)
			move(game, x, y - 1, LEFT);
		else if (keycode == 1 || keycode == 125)
			move(game, x + 1, y, DOWN);
		else if (keycode == 13 || keycode == 126)
			move(game, x - 1, y, UP);

		// else if (keycode == 119)
		// para el egg
		// hacer funcion que cambie C por 0 en el mapa
		// 	game->map.objets.get = game->map.objets.goals;
	}
	return (0);
}

void lap_map(t_game *game, void (*function)(t_game *game, int x, int y, char ch))
{
	int i;
	int j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			function(game, i, j, game->map.map[i][j]);
			j++;
		}
		i++;
	}
}

void window(t_game *game)
{
	char *str;

	mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	str = "github.com/nach131";
	game->grafic.win = mlx_new_window(game->grafic.mlx,
									  game->map.cols * SQUARE,
									  game->map.rows * SQUARE + HEADER, str);
	mlx_hook(game->grafic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
}

void star_game(t_game *game)
{

	init_img(game);
	window(game);
	header(game);
	lap_map(game, locate);
	lap_map(game, filter_wall);
	mlx_key_hook(game->grafic.win, key_hook, game);
	mlx_loop_hook(game->grafic.mlx, (void *)loops, game);
}

int main(int argc, char **argv)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	err_file(argc, argv[1]);
	game.map.map = ft_file_to_dptr(argv[1], 0);
	ctrl_map(&game);
	ctrl_path(&game);
	game.grafic.mlx = mlx_init();
	intro(&game);
	mlx_loop(game.grafic.mlx);
}

