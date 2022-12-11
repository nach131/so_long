/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:19:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/11 16:37:01 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void rush(int h, int v)
{
	int rows;
	int cols;

	cols = 1;
	while (cols <= v && h > 0)
	{
		rows = 1;
		while (rows <= h)
		{
			// top left
			if (rows == 1 && cols == 1)
				ft_putchar('A');
			// Button right
			else if (rows == h && cols == v && rows != 1 && cols != 1)
				ft_putchar('V');
			// top right
			else if (rows == h && cols == 1)
				ft_putchar('C');
			// Button left
			else if (rows == 1 && cols == v)
				ft_putchar('E');

			// center left
			else if (rows == 1)
				ft_putchar('B');
			// center right
			else if (rows == h)
				ft_putchar('G');
			else if (cols == v)
				ft_putchar('F');
			else if (cols == 1)
				ft_putchar('H');
			else
				ft_putchar(' ');
			rows++;
		}
		ft_putchar('\n');
		cols++;
	}
}

int main(int n, char **str)
{
	rush(atoi(str[1]), atoi(str[2]));
}

// 8x8
// AHHHHHHC
// B      G
// B      G
// B      G
// B      G
// B      G
// B      G
// EFFFFFFV
