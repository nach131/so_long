/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:49:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/11 00:31:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"

char	*collections(t_objs colec)
{
	char	*total;
	char	*get;
	char	*s1;
	char	*s2;

	total = ft_itoa(colec.goals);
	get = ft_itoa(colec.get);
	s1 = ft_strjoin(get, "/");
	s2 = ft_strjoin(s1, total);
	free(total);
	free(get);
	free(s1);
	return (s2);
}

void	ctrl_move(t_game *game)
{
	char	*marcador;
	char	*activity;
	int		color;

	if (game->map.objets.get == game->map.objets.goals)
		color = 0x0000FF00;
	else
		color = 0xFFFFFFFF;
	marcador = collections(game->map.objets);
	game->map.objets.move++;
	activity = ft_itoa(game->map.objets.move);
	mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
		game->images.header[3], 75, 43);
	mlx_string_put(game->graphic.mlx, game->graphic.win, 119, 55,
		0xFFFFFFFF, activity);
	mlx_string_put(game->graphic.mlx, game->graphic.win, 80, 55, color, marcador);
	free(marcador);
	free(activity);
}
