/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciona.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:30:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/15 11:31:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/libft/inc/libft.h"
#include "../../sources/libft/inc/ft_printf.h"

void free_cur(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int main(void)
{
	char **cur;
	char *file = "min.ber";
	int i;

	cur = ft_file_to_dptr(file);
	i = 0;
	if (cur)
	{
		while (cur[i])
		{
			ft_printf("%s", cur[i]);
			i++;
		}
	}
	free_cur(cur);
}
