/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/05 21:35:13 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"

void print_arr(char **s)
{
	int i = 0;
	while (s[i])
	{
		ft_printf("%s", s[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_game game;

	if (argc < 2)
	{
		ft_message(DANGER, MSG_DAN_0);
		return (EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_message(DANGER, MSG_DAN_1);
		return (EXIT_FAILURE);
	}

	open_map(argv[1], &game.map);
	// ft_printf("%s", game.map.map[1]);
	print_arr(game.map.map);
	ft_printf("\nrows:%d, cols:%d\n", game.map.rows, game.map.cols);
}
