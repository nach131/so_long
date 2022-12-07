/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/07 17:48:18 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"

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

	printf("\nVALOR DE BOOL: |%zu|\n", sizeof(_Bool));
	err_file(argc, argv[1]);
	open_map(argv[1], &game.map);
	ft_printf("\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
	print_arr_map(&game.map);
	ft_free_map(&game.map); // 11 leaks
	// game.map.map = NULL;
	// free(game.map.map); // 10 leaks

	print_arr_map(&game.map);
}
