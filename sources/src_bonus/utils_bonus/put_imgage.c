/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:35:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/07 12:15:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdlib.h>

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../mlx/mlx.h"

// CAMBIAR EL NOMBRE DEL ARCHIVO

void put_img(t_game *game, char *img, int y, int x)
{
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							img, y * SQUARE, x * SQUARE + HEADER);
}
