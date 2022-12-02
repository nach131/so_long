/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/03 00:36:34 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_all all;

	// if (!all)
	// 	all = (t_all *)ft_calloc(1, sizeof(t_all));
	// if (!all)
	// 	exit(EXIT_FAILURE);
	if (argc < 2)
		ft_message(DANGER, "No hay mapa");

	open_map(argv[1], &all.map);
	open_map(argv[1], &all.map);
	ft_printf("\n\t%d\n", all.map.open);
}
