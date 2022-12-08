/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/08 19:43:03 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "mlx.h"

void print_arr_map(t_map *map)
{
	int i = 0;

	if (map->map)
	{
		while (map->map[i])
		{
			ft_printf("%s", map->map[i]);
			i++;
		}
	}
}

void ft_free_map(t_map *map)
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
}

int main(int argc, char **argv)
{
	t_game game;

	void *mlx_tmp;
	void *win_tmp;
	char *relative_path = "xpm/rocks.xpm";
	void *img;
	int img_width;
	int img_height;

	err_file(argc, argv[1]);
	open_map(argv[1], &game.map);
	// read_map(&game.map);
	mlx_tmp = mlx_init();
	win_tmp = mlx_new_window(mlx_tmp, 640, 480, "nach131 So Long");
	img = mlx_xpm_file_to_image(mlx_tmp, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx_tmp, win_tmp, img, img_width, img_height);
	mlx_loop(mlx_tmp);

	ft_printf("\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
	print_arr_map(&game.map);
	ft_free_map(&game.map); // 11 leaks
	// game.map.map = NULL;
	// free(game.map.map); // 10 leaks

	print_arr_map(&game.map);
}
