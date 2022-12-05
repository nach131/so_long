/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/05 23:16:42 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"

void print_arr(char **s)
{
	int i = 0;
	while (s[i])
	{
		ft_printf("%s", s[i]);
		i++;
	}
}

void ft_free_map(t_map *map)
{
	// int i = 0;
	// while (map->map[i])
	// {
	// 	// map->map[i] = NULL;
	// 	// free(map->map[i]);
	// 	i++;
	// }
	map->map = NULL;
	free(map->map);
}

int main(int argc, char **argv)
{
	t_game game;

	err_file(argc, argv[1]);

	open_map(argv[1], &game.map);
	ft_printf("\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
	print_arr(game.map.map);
	ft_free_map(&game.map);
	// print_arr(game.map.map);
}
