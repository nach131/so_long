/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/04 20:21:21 by nmota-bu         ###   ########.fr       */
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
	int x = game->map.objets.player.x;
	int y = game->map.objets.player.y;

	ft_bzero(&game->dir, sizeof(t_dir));
	game->map.map[x][y] = '0';
	if (keycode == 53)
		exit(0);
	if (keycode == 2 || keycode == 124)
		move(game, x, y + 1, RIGHT);
	if (keycode == 0 || keycode == 123)
		move(game, x, y - 1, LEFT);
	if (keycode == 1 || keycode == 125)
		move(game, x + 1, y, DOWN);
	if (keycode == 13 || keycode == 126)
		move(game, x - 1, y, UP);
	return (0);
}

int free_map(t_game *game)
{
	ft_free_dptr(game->map.map);
	mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	free(game->grafic.mlx);
	free(game->map.map);
	exit(0); // CUIDADO
	return (EXIT_SUCCESS);
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

	str = "github.com/nach131";
	game->grafic.win = mlx_new_window(game->grafic.mlx,
									  game->map.cols * SQUARE,
									  game->map.rows * SQUARE + HEADER, str);
	mlx_hook(game->grafic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
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
	init_img(&game);
	window(&game);
	header(&game);
	lap_map(&game, locate);
	lap_map(&game, filter_wall);

	// PRUEBA DE MOM
	mlx_put_image_to_window(game.grafic.mlx, game.grafic.win,
							game.images.mom[1],
							game.map.objets.enemy.y * SQUARE,
							(game.map.objets.enemy.x * SQUARE) + HEADER);
	// mlx_put_image_to_window(game.grafic.mlx, game.grafic.win,
	// 						game.images.header[3], 69, 43);

	//=============================================================================

	ft_printf(ORANGE "\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
	ft_printf("player: x:%d, y:%d\n", game.map.objets.player.x, game.map.objets.player.y);
	ft_printf("exit: x:%d, y:%d\n", game.map.objets.exit.x, game.map.objets.exit.y);
	ft_printf("enemy: x:%d, y:%d\n", game.map.objets.enemy.x, game.map.objets.enemy.y);

	mlx_key_hook(game.grafic.win, key_hook, &game);
	// mlx_loop_hook(game.grafic.mlx, (void *)loop_door, &game);
	mlx_loop(game.grafic.mlx);
}
