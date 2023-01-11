/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:49:48 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/11 20:59:58 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/libft/inc/libft.h"
#include "../../sources/libft/inc/colors.h"
#include "../../sources/libft/inc/ft_printf.h"

void print_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		ft_printf(MAGENTA "%s\n", map[i]);
		i++;
	}
}

int main(void)
{
	char **map;
	map = ft_file_to_dptr("../../sources/maps/42Barcelona.ber", 0);
	map[0][0] = '@';
	print_map(map);
	exit(0);
}
