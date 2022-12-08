/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:01:07 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/08 15:55:10 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"

void	err_file(int n, char *file)
{
	int	len;

	if (n < 2)
	{
		ft_message(DANGER, MSG_DAN_0);
		exit(EXIT_FAILURE);
	}
	else if (n > 2)
	{
		ft_message(DANGER, MSG_DAN_1);
		exit(EXIT_FAILURE);
	}
	else
	{
		len = ft_strlen(file);
		if (!ft_strnstr(&file[len - 4], ".ber", 4))
		{
			ft_message(DANGER, MSG_DAN_2);
			exit(EXIT_FAILURE);
		}
	}
}

void ctrl_map(t_map *map, char *line)
{
	if (!map->cols)
		map->cols = strlen_line(line);
	if (map->cols != strlen_line(line))
	{
		ft_message(WARNING, MSG_WAR_0);
		exit(EXIT_FAILURE);
	}
}

void ctrl_square(t_map *map)
{
	if (map->cols == map->rows)
	{
		ft_message(WARNING, MSG_WAR_1);
		exit(EXIT_FAILURE);
	}
}

// void read_map(t_map *map)
// {
// }
