/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:07:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/03 00:39:11 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "../../libft/inc/get_next_line.h"
#include <fcntl.h>

void open_map(char *path, t_map *map)
{
	int fd;
	char *line;

	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			map->open = TRUE;
			break;
		}
		else if (line)
		{
			if (map->open == 0)
				ft_printf("%s", line);
			else
				ft_printf(ORANGE "\ntoma");
			if (line)
				free(line);
		}
	}
}
