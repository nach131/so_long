/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/27 16:26:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "../mlx/mlx.h"

int key_hook(int keycode, t_game *game)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	move(game, keycode);
	return (0);
}

int free_map(t_game *game)
{
	int i = 0;

	while (i++ < game->map.rows)
		free(game->map.map[i]);
	mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	free(game->grafic.mlx);
	free(game->map.map);
	exit(0);
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

	str = "nach131 So Long";
	game->grafic.win = mlx_new_window(game->grafic.mlx,
									  game->map.cols * SQUARE,
									  game->map.rows * SQUARE, str);
	mlx_hook(game->grafic.win, ON_DESTROY, 1L << 0, free_map, game);
}

int main(int argc, char **argv)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));
	err_file(argc, argv[1]);
	game.map.map = ft_file_to_dptr(argv[1], 0);
	control_map(&game);
	game.grafic.mlx = mlx_init();
	init_img(&game);
	window(&game);
	lap_map(&game, filter_map);
	lap_map(&game, locate);

	//=============================================================================
	// reload_loop(&game);

	ft_printf(ORANGE "\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
	ft_printf(GREEN "player: %i\n", game.map.objets.player);
	ft_printf("coleccion:%d\n", game.map.objets.goals);
	ft_printf("player: x:%d, y:%d\n", game.map.objets.player.x, game.map.objets.player.y);
	ft_printf("exit: x:%d, y:%d\n", game.map.objets.exit.x, game.map.objets.exit.y);

	// hay que pasar gols a string y juntara todo como con los archivos
	mlx_string_put(game.grafic.mlx, game.grafic.win, 25, 14, 0xffffffff, "toma"); // NACH ESTO ES EL MARCADOR
	mlx_string_put(game.grafic.mlx, game.grafic.win, 25, 28, 0xffffffff, "7/12"); // NACH ESTO ES EL MARCADOR
	mlx_key_hook(game.grafic.win, key_hook, &game);
	// mlx_loop_hook(game.grafic.mlx, reload_loop, &game);
	mlx_loop(game.grafic.mlx);
}
