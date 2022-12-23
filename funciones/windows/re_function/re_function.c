/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:44:06 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/23 14:21:37 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../sources/libft/inc/libft.h"
#include "../../../sources/libft/inc/ft_printf.h"
#include "../../../sources/libft/inc/colors.h"

typedef struct s_game
{
	void *mlx;
	void *win;
	char *textures[6];
	char *logo[40];
	char **map;
	int rows;
	int cols;
} t_game;

#define ROWS 6

void pasada(t_game *game, int x, int y, char ch)
{
	ft_printf(RED "c:%c,x:%d,y%d\n" WHITE, ch, x, y);
}
void pasada_dos(t_game *game, int x, int y, char ch)
{
	ft_printf(ORANGE "c:%c,x:%d,y%d char:%c\n", ch, x, y, ch);
}
void cuenta(t_game *game, int x, int y, char ch)
{
	game->cols++;
	game->rows++;
}

void windows(t_game *game, void (*funcion)(t_game *, int, int, char))
{
	int i = 0;
	int j;

	while (i < ROWS)
	{
		j = 0;
		while (game->map[i][j])
		{
			funcion(game, i, j, game->map[i][j]);
			j++;
		}
		i++;
	}
}

int main(void)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));

	game.map = ft_file_to_dptr("min.ber", 0);
	windows(&game, pasada);
	windows(&game, pasada_dos);
	windows(&game, cuenta);
	ft_printf(GREEN "rows:%d, cols:%d\n", game.rows, game.cols);

	// game.mlx = mlx_init();
	// game.win = mlx_new_window(game.mlx, 20 * 32, ROWS * 32, "nach131 So Long");
	// load_images(&game);
	// windows(&game);
	// mlx_string_put(game.mlx, game.win, 10, 12, 00001010, "toma");	// NACH ESTO ES EL MARCADOR
	// mlx_string_put(game.mlx, game.win, 10, 22, 0xffffffff, "0/12"); // NACH ESTO ES EL MARCADOR
	// mlx_key_hook(game.win, key_hook, &game);
	// mlx_loop_hook(game.mlx, los_dos, &game);
	// mlx_loop(game.mlx);
}

// gcc -framework OpenGL -framework AppKit put_arr_img.c ../../../sources/mlx/libmlx.a ../../../sources/libft/libft.a
