/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:25:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/11/29 16:42:28 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../sources/libft/inc/libft.h"
#include "../sources/libft/inc/ft_printf.h"

int main(void)
{

	// char *s0 = "11111111111111111111";
	// char *s1 = "100000001000000000C1";
	// char *s2 = "10000000011111000001";
	// char *s3 = "1P0000110E0000000001";
	// char *s4 = "11111111111111111111";
	// ft_printf("%s\n", s0);

	char arr[5][21] = {"11111111111111111111",
					   "100000001000000000C1",
					   "10000000011111000001",
					   "1P0000110E0000000001",
					   "11111111111111111111"};

	int arr_len = sizeof(arr) / sizeof(arr[0]);

	// ft_printf("primer item: %s\n", arr[0]);
	// ft_printf("arr tiene: %i elementos\n", arr_len);

	t_list *map;
	t_list *tmp;

	map = (t_list *)ft_calloc(1, sizeof(t_list));

	int i = 0;
	while (i < arr_len)
	{
		// ft_printf("item arr[%i]: %s\n", i, arr[i]);
		tmp = ft_lstnew(ft_strdup(arr[i]));
		ft_lstadd_back(&map, tmp); //
		// ft_lstadd_front(&map, tmp);
		tmp = (t_list *)ft_calloc(1, sizeof(t_list));
		free(tmp);
		i++;
	}
	t_list *con = map;
	while (con)
	{
		ft_printf("list: %s\n", con->content);
		ft_printf("list: %s\n", con->content);
		con = con->next;
	}
}

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

// list: (null)
// list: 11111111111111111111
// list: 100000001000000000C1
// list: 10000000011111000001
// list: 1P0000110E0000000001
// list: 11111111111111111111
