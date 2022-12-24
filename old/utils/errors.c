/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:01:07 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/24 11:09:09 by nmota-bu         ###   ########.fr       */
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

int ctrl_wall(t_map map, int rows, int cols, char ch)
{
	int h = map.rows - 1;
	int v = map.cols - 1;

	if ((rows == 0 && cols <= v) && ch != '1')
		ft_printf(GREEN "\trow:%d col:%d\n" WHITE, rows, cols);
	else if ((rows > 0 && cols == 0) && ch != '1')
		ft_printf(GREEN "\trow:%d col:%d\n" WHITE, rows, cols);
	else if ((rows > 0 && cols == v) && ch != '1')
		ft_printf(GREEN "\trow:%d col:%d\n" WHITE, rows, cols);
	else if ((rows == h && cols <= v) && ch != '1')
		ft_printf(GREEN "\trow:%d col:%d\n" WHITE, rows, cols);
	else
		return (0);
	return (1);
}
