/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:07:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/04 02:30:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "../../libft/inc/get_next_line.h"
#include <fcntl.h>

static int strlen_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	// AQUI SE PODRIA CONTROLAR LA SALIDA, PLAYER, COLECCIONABLE...
	return (i);
}

static void ctrl_map(t_map *map, char *line)
{
	if (!map->cols)
		map->cols = strlen_line(line);
	if (map->cols != strlen_line(line))
	{
		ft_message(WARNING, MSG_WAR_0);
		exit(EXIT_FAILURE);
	}
}

// void static write_map()
// {
// }

void open_map(char *path, t_map *map)
{
	int fd;
	char *line;

	if (!map->cols)
		map->cols = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			// FUNCION close_map todo esto
			map->open = TRUE;
			close(fd);
			if (map->map)
				break;
			// open_map(path, map);
		}
		else if (line)
		{
			if (map->open == 0)
			{
				ctrl_map(&(*map), line);
				// ft_printf("%s", line);
				map->rows += 1;
			}
			else
			{
				ft_printf(ORANGE "\ntoma");
			}
			if (line)
				free(line);
		}
	}
	// HACERLA RECURSIVA que se llame y vuelva asi no la pongo dos veces
	// en la segunda vuelta a poener a 0 el flag
}
