/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/20 18:36:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../mlx/mlx.h"

int	key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	game->key = TRUE;
	x = game->map.objets.player.x;
	y = game->map.objets.player.y;
	ft_bzero(&game->dir, sizeof(t_dir));
	game->map.map[x][y] = '0';
	if (keycode == KEY_ESC)
		exit(0);
	if (!game->gameover)
	{
		if (keycode == KEY_D || keycode == KEY_RIGHT)
			move(game, x, y + 1, RIGHT);
		else if (keycode == KEY_A || keycode == KEY_LEFT)
			move(game, x, y - 1, LEFT);
		else if (keycode == KEY_S || keycode == KEY_DOWN)
			move(game, x + 1, y, DOWN);
		else if (keycode == KEY_W || keycode == KEY_UP)
			move(game, x - 1, y, UP);
	}
	return (0);
}

void	lap_map(t_game *game,
		void (*function)(t_game *game, int x, int y, char ch))
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

	mlx_destroy_window(game->graphic.mlx, game->graphic.win);
	str = "github.com/nach131";
	game->graphic.win = mlx_new_window(game->graphic.mlx,
			game->map.cols * SQUARE, game->map.rows * SQUARE + HEADER, str);
	mlx_hook(game->graphic.win, ON_DESTROY, 1L << 0, (void *)exit, NULL);
}

void	star_game(t_game *game)
{
	init_img(game);
	window(game);
	header(game);
	lap_map(game, locate);
	lap_map(game, filter_wall);
	mlx_key_hook(game->graphic.win, key_hook, game);
	mlx_loop_hook(game->graphic.mlx, (void *)loops, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	err_file(argc, argv[1]);
	game.map.map = ft_file_to_dptr(argv[1], 0);
	ctrl_map(&game);
	ctrl_path(&game);
	if (game.map.tmp)
		ft_free_dptr(game.map.tmp);
	game.map.tmp = ft_cp_dptr(game.map.map);
	game.graphic.mlx = mlx_init();
	intro(&game);
	mlx_loop(game.graphic.mlx);
}
