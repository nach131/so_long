/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:07:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/15 01:50:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "../../libft/inc/get_next_line.h"
#include <fcntl.h>

void static write_map(t_map *map, char *line, int i)
{
	if (!map->map)
		map->map = ft_calloc(map->rows + 1, sizeof(char *));
	map->map[i] = ft_substr(line, 0, 0xffffffff);
}

void static is_line(char *line, t_map *map, int *rows)
{
	if (map->control == FALSE)
	{
		ctrl_map(&(*map), line);
		map->rows += 1; // AQUI SUMO
	}
	else
	{
		write_map(&(*map), line, *rows);
		map->write = TRUE;
		*rows += 1;
	}
}

void open_map(char *path, t_map *map)
{
	int fd;
	char *line;
	int ptr;

	ptr = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_message(DANGER, MSG_DAN_3);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			map->control = TRUE;
			close(fd);
			if (map->write)
				break;
			open_map(path, map);
		}
		else if (line)
			is_line(line, &(*map), &ptr);
		free(line);
	}
}
