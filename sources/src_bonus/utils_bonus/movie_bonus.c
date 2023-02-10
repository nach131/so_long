/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:33:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/11 00:31:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../../mlx/mlx.h"

void	simple_key(int key, t_game *game)
{
	(void)game;
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_R)
		restar_game(game);
}

void static	loops_end(t_game *game)
{
	int static	i = 0;
	int static	frame = 0;

	if (!(frame % 600))
	{
		if (game->won)
		{
			mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
				game->images.endgame[i], 0, 0);
			if (i == 90 - 1)
				i = 0;
		}
		else
		{
			mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
				game->images.endgame[i], 0, 0);
			if (i == 103 - 1)
				i = 0;
		}
		i++;
		frame = 1;
	}
	else
		frame++;
}

void static	end_win(t_game *game, char *str)
{
	mlx_destroy_window(game->graphic.mlx, game->graphic.win);
	game->graphic.win = mlx_new_window(game->graphic.mlx, 854, 480, str);
	mlx_hook(game->graphic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
	mlx_key_hook(game->graphic.win, (void *)simple_key, game);
	mlx_loop_hook(game->graphic.mlx, (void *)loops_end, game);
}

void	endgame(t_game *game)
{
	if (game->won)
	{
		load_img_two(game, "won", 90, END_ANI);
		end_win(game, "You won and that's Big Mom hates you with hatred");
	}
	else
	{
		load_img_two(game, "lose", 103, END_ANI);
		end_win(game, "You lose and Big Mom don't give a f***");
	}
}
