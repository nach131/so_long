/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:25:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/29 20:11:25 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../sources/libft/inc/libft.h"
#include "../sources/libft/inc/ft_printf.h"
#include "../sources/libft/inc/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// void line_to_map(t_list **map, char *line)
// {
// 	t_list *tmp;
// 	tmp = ft_lstnew(line);
// 	ft_lstadd_back(&map, tmp); //
// 	tmp = (t_list *)ft_calloc(1, sizeof(t_list));
// 	free(tmp);
// }

void printLista(t_list *lst)
{
	while (lst)
	{
		printf("\e[5;32m\t%s\n\e[0m", lst->content);
		lst = lst->next;
	}
}

int main(int argc, char **argv)
{

	char *line;
	int fd;

	fd = open(argv[1], O_RDONLY);

	t_list *map;
	t_list *tmp;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			line = get_next_line(fd);
			// tmp = ft_lstnew(ft_strdup(arr[i]));
			break;
		}
		else if (line)
		{
			// line_to_map(&map, line);

			t_list *tmp;
			tmp = ft_lstnew(line);
			ft_lstadd_back(&map, tmp);
			tmp = (t_list *)ft_calloc(1, sizeof(t_list));
			free(tmp);

			// printf("%s", line);
			// printf("----------------\n");
			if (line)
			{

				free(line);
			}
		}
	}

	printLista(map);

	// t_list *con = map;
	// while (con)
	// {
	// 	// ft_printf("list: %s\n", con->content);
	// 	printf("list: %s\n", con->content);
	// 	con = con->next;
	// }
}

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;
