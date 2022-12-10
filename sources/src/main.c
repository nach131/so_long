/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/08 21:48:09 by nmota-bu         ###   ########.fr       */
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

int ft_free_map(t_map *map)
{
	int i = 0;

	while (i < map->rows)
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	map->rows = 0;
	map->cols = 0;
	free(map->map);
	map->map = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

void put_windows(t_game *game)
{
	char *relative_path = ROCKS;
	void *img;
	int img_width;
	int img_height;
	// game->grafic.win = mlx_new_window(game->grafic.mlx, 640, 480, "nach131 So Long");
	game->grafic.win = mlx_new_window(game->grafic.mlx, game->map.cols * SQUARE,
									  game->map.rows * SQUARE, "nach131 So Long");
	img = mlx_xpm_file_to_image(game->grafic.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, img, img_width, img_height);

	mlx_hook(game->grafic.win, WIN_CLOSE, 0, ft_free_map, game);
}

int main(int argc, char **argv)
{
	t_game game;

	// char *relative_path = "xpm/rocks.xpm";

	err_file(argc, argv[1]);
	open_map(argv[1], &game.map);
	// read_map(&game.map);
	game.grafic.mlx = mlx_init();

	put_windows(&game);
	mlx_loop(game.grafic.mlx);

	// ft_printf("\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
	// print_arr_map(&game.map);
	// ft_free_map(&game.map);
}
