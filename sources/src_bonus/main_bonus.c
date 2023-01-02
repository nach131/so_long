/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/02 23:23:05 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../mlx/mlx.h"

// 2-124  D
// 0-123  A
// 1-125  S
// 13-126 W

int key_hook(int keycode, t_game *game)
{
	int x = game->map.objets.player.x;
	int y = game->map.objets.player.y;

	game->map.map[x][y] = '0';
	if (keycode == 53)
		exit(0);
	if (keycode == 2 || keycode == 124)
		move(game, x, y + 1, 0);
	if (keycode == 0 || keycode == 123)
		move(game, x, y - 1, 1);
	if (keycode == 1 || keycode == 125)
		move(game, x + 1, y, 2);
	if (keycode == 13 || keycode == 126)
		move(game, x - 1, y, 3);
	return (0);
}

int free_map(t_game *game)
{

	exit(0); // CUIDADO
	ft_free_dptr(game->map.map);
	mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	free(game->grafic.mlx);
	free(game->map.map);
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
	// mlx_hook(game->grafic.win, ON_DESTROY, 1L << 0, free_map, game);
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
	// reload_loop(&game);

	ft_printf(ORANGE "\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
	// ft_printf("coleccion:%d\n", game.map.objets.goals);
	// ft_printf("conseguidos:%d\n", game.map.objets.get);
	ft_printf("player: x:%d, y:%d\n", game.map.objets.player.x, game.map.objets.player.y);
	ft_printf("exit: x:%d, y:%d\n", game.map.objets.exit.x, game.map.objets.exit.y);
	ft_printf("enemy: x:%d, y:%d\n", game.map.objets.enemy.x, game.map.objets.enemy.y);

	// hay que pasar gols a string y juntara todo como con los archivos
	mlx_loop_hook(game.grafic.mlx, reload, &game);
	mlx_key_hook(game.grafic.win, key_hook, &game);
	mlx_loop(game.grafic.mlx);
}
