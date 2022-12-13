/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/13 08:53:06 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "mlx.h"

// void print_arr_map(t_map *map)
// {
// 	int i = 0;

// 	if (map->map)
// 	{
// 		while (map->map[i])
// 		{
// 			ft_printf("%s", map->map[i]);
// 			i++;
// 		}
// 	}
// }

// int ft_free_map(t_map *map)
// {
// 	int i = 0;

// 	while (i < map->rows)
// 	{
// 		free(map->map[i]);
// 		map->map[i] = NULL;
// 		i++;
// 	}
// 	map->rows = 0;
// 	map->cols = 0;
// 	free(map->map);
// 	map->map = NULL;
// 	exit(EXIT_SUCCESS);
// 	return (0);
// }
int ft_free_map(t_game *game)
{
	int i = 0;

	while (i < game->map.rows)
	{
		free(game->map.map[i]);
		game->map.map[i] = NULL;
		i++;
	}
	mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	free(game->grafic.mlx);
	free(game->map.map);
	game->map.map = NULL;
	exit(EXIT_SUCCESS);
	return (0);
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

// void init_game(t_game *game)
// {
// 	game->map.objets.player.is = 0;
// 	game->map.objets.exit.is = 0;
// }

int main(int argc, char **argv)
{
	t_game game;

	err_file(argc, argv[1]);
	open_map(argv[1], &game.map);
	// init_game(&game);
	read_map(&game);
	game.grafic.mlx = mlx_init();

	// ft_printf(GREEN "%i", game.objets.goals);
	put_windows(&game);
	ft_printf(ORANGE "\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
	ft_printf("coleccion:%d\n", game.map.objets.goals);
	ft_printf("player: x:%d, y:%d\n", game.map.objets.player.x, game.map.objets.player.y);
	ft_printf("exit: x:%d, y:%d\n", game.map.objets.exit.x, game.map.objets.exit.y);
	mlx_loop(game.grafic.mlx);

	// print_arr_map(&game.map);
	// ft_free_map(&game.map);
}
