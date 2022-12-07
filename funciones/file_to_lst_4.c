/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_lst_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:25:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/07 02:48:25 by nmota-bu         ###   ########.fr       */
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
		ft_printf(GREEN "%s", lst->content);
		lst = lst->next;
	}
}

int ft_len_line(int fd)
{
	int len = 0;
	char *line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (len);
}

void ft_item_add_back(t_list **lst, char *str)
{
	t_list *l_aux;

	// l_aux = ft_lstlast(*lst);
	// l_aux->content = str;
	int i = 0;
	if (!(*lst)->content)
		(*lst)->content = str;
	else
	{
		l_aux = ft_lstlast(*lst); /// AQUI QUEDE
		l_aux->content = str;
	}
	ft_printf("nada\n");
}

t_list *nach_lstnew(char *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int i = 0;
	int len;

	// fd = open(argv[1], O_RDONLY);
	fd = open("../sources/maps/veinte.ber", O_RDONLY);

	t_list *map;
	t_list *tmp;
	map = ft_calloc(1, sizeof(t_list));

	line = get_next_line(fd);
	while (line)
	{
		// ft_item_add_back(&map, line);
		tmp = nach_lstnew(line);
		ft_lstadd_back(&map, tmp);
		free(line);
		line = get_next_line(fd);
	}

	printLista(map);
	ft_lstclear(&map, ft_delitem);
}

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

// https://www.learn-c.org/en/Linked_lists

// https://stackoverflow.com/questions/46820999/code-to-add-element-to-the-beginning-of-a-list-in-c-whats-the-error
