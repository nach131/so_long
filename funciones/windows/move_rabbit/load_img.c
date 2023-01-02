/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:17:39 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/02 14:30:06 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "header.h"

void load_images(t_game *game)
{
	int width;
	int height;

	game->textures[ROCKS] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/gwall/gwall0.xpm", &width, &height);
	game->textures[TGREEN] = mlx_xpm_file_to_image(game->mlx, "../xpm/tree_GREEN.xpm", &width, &height);
	game->textures[GRASS] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/floor/floor0.xpm", &width, &height);
	game->textures[DOORC] = mlx_xpm_file_to_image(game->mlx, "../xpm/door_closed.xpm", &width, &height);
	game->textures[ROJO] = mlx_xpm_file_to_image(game->mlx, "../xpm/rojo.xpm", &width, &height);
	game->logo[0] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo0.xpm", &width, &height);
	game->logo[1] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo1.xpm", &width, &height);
	game->logo[2] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo2.xpm", &width, &height);
	game->logo[3] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo3.xpm", &width, &height);
	game->logo[4] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo4.xpm", &width, &height);
	game->logo[5] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo5.xpm", &width, &height);
	game->logo[6] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo6.xpm", &width, &height);
	game->logo[7] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo7.xpm", &width, &height);
	game->logo[8] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo8.xpm", &width, &height);
	game->logo[9] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo9.xpm", &width, &height);
	game->logo[10] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo10.xpm", &width, &height);
	game->logo[11] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo11.xpm", &width, &height);
	game->logo[12] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo12.xpm", &width, &height);
	game->logo[13] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo13.xpm", &width, &height);
	game->logo[14] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo14.xpm", &width, &height);
	game->logo[15] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo15.xpm", &width, &height);
	game->logo[16] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo16.xpm", &width, &height);
	game->logo[17] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo17.xpm", &width, &height);
	game->logo[18] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo18.xpm", &width, &height);
	game->logo[19] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo19.xpm", &width, &height);
	game->logo[20] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo20.xpm", &width, &height);
	game->logo[21] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo21.xpm", &width, &height);
	game->logo[22] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo22.xpm", &width, &height);
	game->logo[23] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo23.xpm", &width, &height);
	game->logo[24] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo24.xpm", &width, &height);
	game->logo[25] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo25.xpm", &width, &height);
	game->logo[26] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo26.xpm", &width, &height);
	game->logo[27] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo27.xpm", &width, &height);
	game->logo[28] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo28.xpm", &width, &height);
	game->logo[29] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo29.xpm", &width, &height);
	game->logo[30] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo30.xpm", &width, &height);
	game->logo[31] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo31.xpm", &width, &height);
	game->logo[32] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo32.xpm", &width, &height);
	game->logo[33] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo33.xpm", &width, &height);
	game->logo[34] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo34.xpm", &width, &height);
	game->logo[35] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo35.xpm", &width, &height);
	game->logo[36] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo36.xpm", &width, &height);
	game->logo[37] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo37.xpm", &width, &height);
	game->logo[38] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo38.xpm", &width, &height);
	game->logo[39] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo39.xpm", &width, &height);
	game->hero[0] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/rabbit_bonus/rabbit0.xpm", &width, &height);
	game->hero[1] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/rabbit_bonus/rabbit1.xpm", &width, &height);
	game->hero[2] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/rabbit_bonus/rabbit2.xpm", &width, &height);
	game->hero[3] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/rabbit_bonus/rabbit3.xpm", &width, &height);
	game->hero[4] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/rabbit_bonus/rabbit4.xpm", &width, &height);
	game->hero[5] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/rabbit_bonus/rabbit5.xpm", &width, &height);
	game->hero[6] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/rabbit_bonus/rabbit6.xpm", &width, &height);
	game->hero[7] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/rabbit_bonus/rabbit7.xpm", &width, &height);
	game->mom[0] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/mom/mom4.xpm", &width, &height);
	game->mom[1] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/mom/mom5.xpm", &width, &height);
	game->mom[2] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/mom/mom6.xpm", &width, &height);
	game->mom[3] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/mom/mom7.xpm", &width, &height);
}
