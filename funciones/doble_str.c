/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doble_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:22:12 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/28 12:21:07 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../sources/libft/inc/libft.h"
#include "../sources/libft/inc/ft_printf.h"
#include "../sources/libft/inc/colors.h"

char **copia(char **ori)
{
	int rows = 0;
	int i = 0;
	char **res;

	while (ori[rows])
		rows++;
	res = (char **)ft_calloc(rows + 1, sizeof(char *));

	while (i < rows)
	{
		res[i] = ft_substr(ori[i], 0, 0xFFFFFFF);
		i++;
	}
	return (res);
}

int main(void)
{
	char **str;
	str = ft_file_to_dptr("../sources/maps/min.ber", 0);
	char **res;
	res = copia(str);

	int i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
	i = 0;
	while (res[i])
	{
		ft_printf(GREEN "%s\n", res[i]);
		i++;
	}
	ft_printf("ori: %p\n", str);
	ft_printf("cp: %p\n", res);
	ft_free_dptr(str);
	ft_free_dptr(res);
}

// ../sources/libft/libft.a
