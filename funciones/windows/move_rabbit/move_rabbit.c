/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rabbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:13:34 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/09 17:36:29 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "header.h"

void free_img(t_game *game)
{
	int i = -1;
	if (game->hero[0] != NULL)
		while (++i < 8)
			mlx_destroy_image(game->mlx, game->hero[i]);
	mlx_destroy_window(game->mlx, game->win);

	// i = -1;
	// if (game->logo[0] == NULL)
	// 	while (++i < 39)
	// 		mlx_destroy_image(game->mlx, game->logo[i]);
}

int key_hook(int keycode, t_game *game)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == 53)
	{
		free_img(game);
		exit(0);
	}
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
	if (!(fps % 100))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->logo[i], y, x);
		if (i == 38)
		{
			i = 0;
			game->flag = 0;
		}
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

	if (!(fps % 250))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->hero[i], y, x);
		if (i == 7)
		{
			i = 0;
			game->flag = 1;
		}
		fps = 1;
		i++;
	}
	else
	{
		fps++;
	}
}

int find_hero(t_game *game)
{
	int i = 0;
	int j;

	while (i < ROWS)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				put_hero(game, i, j);
			// else if (game->map[i][j] == 'C')
			// 	put_logo(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
void find_logo(t_game *game)
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
			j++;
		}
		i++;
	}
}

void los_dos(t_game *game)
{
	if (game->flag == 0)
		find_hero(game);
	// else if (game->flag == 1)
	// 	find_logo(game);
}

int main(void)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));
	game.map = ft_file_to_dptr("min.ber", 0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 20 * 32, ROWS * 32, "nach131 So Long");
	load_img(&game, "rabbit_r", 8, HERO);
	// load_img(&game, "logo", 39, LOGO);
	load_img(&game, "mom", 1, MOM);
	mlx_put_image_to_window(game.mlx, game.win, game.mom->content, 4, 4);

	mlx_loop_hook(game.mlx, (void *)los_dos, &game);
	mlx_key_hook(game.win, key_hook, &game);

	mlx_loop(game.mlx);
}

// gcc -framework OpenGL -framework AppKit move_rabbit.c load_img.c ../../../sources/mlx/libmlx.a ../../../sources/libft/libft.a
