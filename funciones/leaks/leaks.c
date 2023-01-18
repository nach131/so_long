/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:39:57 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/18 19:29:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/libft/inc/libft.h"

#define ROWS 10
#define COLS 5

void free_arr_int(void **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int main(void)
{
	void **collected;
	int i;

	collected = (void **)ft_calloc(ROWS + 1, sizeof(void *));
	i = 0;
	while (i < ROWS)
	{
		collected[i] = (void *)ft_calloc(COLS + 1, sizeof(void *));
		i++;
	}
	free_arr_int(collected);
}
