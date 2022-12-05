/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:07:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/05 22:19:24 by nmota-bu         ###   ########.fr       */
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

void static write_map(t_map *map, char *line, int i)
{
	if (!map->map)
		map->map = (char **)calloc(map->rows + 1, sizeof(char *));
	map->map[i] = ft_strdup(line);

	// ft_printf("%s", line);
}

void open_map(char *path, t_map *map)
{
	int fd;
	char *line;
	int rows;

	if (!map->cols)
		map->cols = 0;
	fd = open(path, O_RDONLY);
	rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			// separar a FUNCION close_map todo esto
			map->open = TRUE;
			close(fd);
			if (map->write)
				break;
			open_map(path, map);
		}
		else if (line)
		{
			if (map->open == FALSE)
			{
				ctrl_map(&(*map), line);
				map->rows += 1;
			}
			else
			{
				write_map(&(*map), line, rows);
				map->write = TRUE;
				rows += 1;
			}
			if (line)
				free(line);
		}
	}
}
