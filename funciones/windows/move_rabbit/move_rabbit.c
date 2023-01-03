/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rabbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:13:34 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/03 11:35:35 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "header.h"

int key_hook(int keycode, t_game *game)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 13) // W
	{
		;
		// map[4][1] = '0';
		// map[4][2] = 'P';
		// mlx_put_image_to_window(mlx, win, textures[GRASS], 4, 2, logo);
		// mlx_put_image_to_window(mlx, win, textures[GRASS], 4, 2);
	}
	else if (keycode == 2) // D
	{
		ft_printf(ORANGE "%c\n" WHITE, game->map[4][1]);
		game->map[4][1] = '0';
		game->map[4][2] = 'P';
		// move_r(game);
	}
	else if (keycode == 0) // A
	{
		ft_printf(ORANGE "%c\n" WHITE, game->map[4][2]);
		game->map[4][2] = '0';
		game->map[4][1] = 'P';
		// move_l(game);
	}
	else if (keycode == 1)
		;
	return (0);
}

void put_logo(t_game *game, int x, int y)
{
	int static i;
	int static fps = 0;

	if (!i)
		i = 0;
	x *= 32;
	y *= 32;

	// if (!(fps % 5))
	if (!(fps % 25))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->logo[i], y, x);
		if (i == 38)
			i = 0;
		i++;
		fps = 1;
	}
	else
	{
		fps++;
	}
}

void put_hero(t_game *game, int x, int y)
{
	int static i;
	int static fps = 0;

	if (!i)
		i = 0;
	x *= 32;
	y *= 32;

	if (!(fps % 20))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->hero[i], y, x);
		if (i == 7)
			i = 0;
		i++;
		fps = 1;
	}
	else
	{
		fps++;
	}
}

int loop_logo(t_game *game)
{
	int i = 0;
	int j;

	while (i < ROWS)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				put_logo(game, i, j);
			else if (game->map[i][j] == 'P')
				put_hero(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void los_dos(t_game *game)
{

	loop_logo(game);
	// windows(game);
	// loop_mom(game);
	// loop_hero(game);
	// return (0);
}

int main(void)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));
	game.map = ft_file_to_dptr("min.ber", 0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 20 * 32, ROWS * 32, "nach131 So Long");
	load_images(&game);
	// init_game(&game); // localiza enemy
	// printf("x:%d, y:%d\n", game.enemy.x, game.enemy.y);
	// windows(&game);

	mlx_loop_hook(game.mlx, (void *)loop_logo, &game);
	mlx_key_hook(game.win, key_hook, &game);

	//===========================================================================================
	// mlx_expose_hook(game.win, loop_mom, &game);
	// mlx_loop_hook(game.mlx, loop_hero, &game);

	mlx_loop(game.mlx);
}

//  gcc -framework OpenGL -framework AppKit move_rabbit.c load_img.c  ../../../sources/mlx/libmlx.a ../../../sources/libft/libft.a && ./a.out

// ORDEN

// mlx_loop_hook(g->id, ft_update, (void *)g);
//  SI HAY QUE REDIBUJAR

// mlx_hook(g->w_id, 17, 0, end_game, (void *)g);
// mlx_key_hook(g->w_id, key_hook, (void *)g);
// mlx_loop(g->id);
