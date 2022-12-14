/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:16:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/13 23:16:37 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:04:01 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/13 15:15:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "../../mlx/mlx.h"
#include <stdlib.h>
#include <time.h>

void static put_img(t_game *game, int x, int y, char *path)
{
	int img_width;
	int img_height;

	game->grafic.img = mlx_xpm_file_to_image(game->grafic.mlx,
											 path, &img_width, &img_height);
	mlx_put_image_to_window(game->grafic.mlx,
							game->grafic.win, game->grafic.img, y, x);
}

void random_item(t_game *game, int x, int y)
{
	int number = rand() % 5;
	// char arr[6][24];

	// usleep(10000);

	srand(time(NULL));
	char arr[6][24] = {"xpm/mis/rocks.xpm",
					   "xpm/mis/rock.xpm",
					   "xpm/mis/tree_green.xpm",
					   "xpm/mis/tree_moles.xpm",
					   "xpm/mis/tree_orange.xpm",
					   "xpm/mis/tree_ping.xpm"};

	put_img(game, x, y, arr[number]);
}

void static wall(t_game *game, int x, int y)
{
	int h;
	int v;

	h = (game->map.rows * 32) - 32;
	v = (game->map.cols * 32) - 32;
	if (x == 0 && y == 0)
		put_img(game, 0, 0, WELL_TL);
	else if (x == h && y == v && x != 0 && y != 0)
		put_img(game, x, y, WELL_BR);
	else if (y == v && x == 0)
		put_img(game, x, y, WELL_TR);
	else if (x == h && y == 0)
		put_img(game, x, y, WELL_BL);
	else if (x == h)
		put_img(game, x, y, WELL_BC);
	else if (y == v)
		put_img(game, x, y, WELL_CR);
	else if (y == 0)
		put_img(game, x, y, WELL_CL);
	else if (x == 0)
		put_img(game, x, y, WELL_TC);
	else
		// AQUI FUNCION PONGO ALEATORIO
		// put_img(game, x, y, TMOLES);
		random_item(game, x, y);
}

void filter_map(t_game *game, int x, int y, char ch)
{
	if (x != 0 || y != 0)
	{
		x *= SQUARE;
		y *= SQUARE;
	}
	if (ch == '1')
		wall(game, x, y);
	if (ch == '0')
		put_img(game, x, y, GRASS);
	if (ch == 'P')
		// segun el personeje eleguido se cargara la imagen
		put_img(game, x, y, FROG_F);
	if (ch == 'E')
		put_img(game, x, y, DOORC);
	if (ch == 'C')
		put_img(game, x, y, ICOL);
}
