/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitonb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:39:36 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/05 17:52:37 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/libft/inc/ft_printf.h"
#include "../../sources/libft/inc/get_next_line.h"
#include <fcntl.h>

void cambio(char *str)
{
	// ft_printf("%s", str);
	int i = 0;

	while (str[i] != '\0')
	{

		if (str[i] == '1')
			str[i] = '0';
		else if (str[i] == '0')
			str[i] = '1';
		// if (str[i] == 2584)
		// 	ft_printf(RED "aaa", );
		ft_printf("%c", str[i]);
		i++;
	}
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break;
		}
		else if (line)
		{
			// ft_printf("%s", line);
			cambio(line);
			if (line)
				free(line);
		}
	}
}

// ▄
// LOWER HALF BLOCK
// Unicode: U+2584, UTF-8: E2 96 84
// ░
// LIGHT SHADE
// Unicode: U+2591, UTF-8: E2 96 91
