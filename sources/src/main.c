/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/21 14:22:21 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
// #include "mlx.h"
#include "../mlx/mlx.h"

int key_hook(int keycode, t_game *game)
{
	(void)game;
	printf("Keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 13) // W
		;
	else if (keycode == 0)
		;
	else if (keycode == 1)
		;
	return (0);
}

// void free_img(t_images *img, int nb)
// {
// 	int i;

// 	i = 0;
// 	while (i++ < nb)
// 	{
// 		free(img->g_wall[i]);
// 		// ft_printf(RED "%s", img->g_wall[i]);
// 	}
// }

// int count_rows(char **map)
// {
// 	int i = 0;
// 	while (map[i])
// 		i++;
// 	return (i);
// }

int ft_free_map(t_game *game)
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

void put_windows(t_game *game)
{
	char *str;
	int i;
	int j;

	str = "nach131 So Long";
	game->grafic.win = mlx_new_window(game->grafic.mlx,
									  game->map.cols * SQUARE,
									  game->map.rows * SQUARE, str);
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			filter_map(game, i, j, game->map.map[i][j]);
			j++;
		}
		i++;
	}
	mlx_hook(game->grafic.win, ON_DESTROY, 1L << 0, ft_free_map, game);
}

int main(int argc, char **argv)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));
	err_file(argc, argv[1]); // esto se puede quitar por la nueva funcion.

	// game.map.map = ft_file_to_dptr(argv[1], 1);
	// game.map.rows = count_rows(game.map.map);

	open_map(argv[1], &game.map);

	read_map(&game);
	game.grafic.mlx = mlx_init();

	// ft_printf(GREEN "%i", game.objets.goals);
	init_img(&game);
	put_windows(&game);

	ft_printf(ORANGE "\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
	ft_printf("coleccion:%d\n", game.map.objets.goals);
	ft_printf("player: x:%d, y:%d\n", game.map.objets.player.x, game.map.objets.player.y);
	ft_printf("exit: x:%d, y:%d\n", game.map.objets.exit.x, game.map.objets.exit.y);
	mlx_string_put(game.grafic.mlx, game.grafic.win, 18, 20, 00001010, "toma");	  // NACH ESTO ES EL MARCADOR
	mlx_string_put(game.grafic.mlx, game.grafic.win, 18, 30, 0xffffffff, "0/12"); // NACH ESTO ES EL MARCADOR
	mlx_key_hook(game.grafic.win, key_hook, &game);
	mlx_loop(game.grafic.mlx);
}
