/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:01:07 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/23 19:09:18 by nmota-bu         ###   ########.fr       */
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
