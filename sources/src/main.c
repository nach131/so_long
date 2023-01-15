/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/15 14:07:26 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "../mlx/mlx.h"

int	key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->map.objets.player.x;
	y = game->map.objets.player.y;
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

void	lap_map(t_game *game, void (*function)
		(t_game *game, int x, int y, char ch))
{
	int	i;
	int	j;

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

void	window(t_game *game)
{
	char	*str;

	mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	str = "github.com/nach131";
	game->grafic.win = mlx_new_window(game->grafic.mlx,
			game->map.cols * SQUARE,
			game->map.rows * SQUARE + HEADER, str);
	mlx_hook(game->grafic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
}

void	star_game(t_game *game)
{
	init_img(game);
	window(game);
	header(game);
	lap_map(game, filter_map);
	lap_map(game, locate);
	mlx_key_hook(game->grafic.win, key_hook, game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	ft_bzero(&game, sizeof(t_game));
	err_file(argc, argv[1]);
	game.map.map = ft_file_to_dptr(argv[1], 0);
	ctrl_map(&game);
	ctrl_path(&game);
	game.grafic.mlx = mlx_init();
	intro(&game);
	mlx_loop(game.grafic.mlx);
}
