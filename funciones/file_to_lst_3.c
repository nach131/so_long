/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_lst_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:25:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/07 00:50:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../sources/libft/inc/libft.h"
#include "../sources/libft/inc/ft_printf.h"
#include "../sources/libft/inc/get_next_line.h"
#include "../sources/libft/inc/colors.h"
#include <fcntl.h>

void printLista(t_list *lst)
{
	while (lst)
	{
		// printf("\e[5;32m%s\e[0m", lst->content);
		ft_printf(GREEN "%s", lst->content);
		lst = lst->next;
	}
}

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int i = 0;

	// fd = open(argv[1], O_RDONLY);
	fd = open("../sources/maps/veinte.ber", O_RDONLY);

	t_list *map;
	t_list *tmp;

	while (i < 6)
	{
		tmp = ft_lstnew(get_next_line(fd));
		ft_lstadd_back(&map, tmp);
		i++;
	}

	printLista(map);
	ft_lstclear(&map, ft_delitem);
}

// 11111111111111111111
// 10000000000000000001
// 100000001000000000C1
// 10000000011111000001
// 1P0000110E0000000001
// 11111111111111111111

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;
