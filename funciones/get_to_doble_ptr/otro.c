/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:29:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/15 11:08:40 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <fcntl.h>
#include "../../sources/libft/inc/error.h"
#include "../../sources/libft/inc/libft.h"
#include "../../sources/libft/inc/ft_printf.h"
#include "../../sources/libft/inc/get_next_line.h"

#define MSG_DAN_0 "Error 0: Missing file"
#define MSG_DAN_1 "Error 1: Too many arguments"
#define MSG_DAN_3 "Error 3: File not found"

// void err_file(int n, char *file)
// {
// 	int len;

// 	if (n < 2)
// 	{
// 		ft_message(DANGER, MSG_DAN_0);
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (n > 2)
// 	{
// 		ft_message(DANGER, MSG_DAN_1);
// 		exit(EXIT_FAILURE);
// 	}
// }

void static is_line(char *line, char **res, int *rows, int control, int *write)
{
	int static i;

	if (!i)
		i = 0;
	if (control == FALSE)
		*rows += 1;
	else
	{
		res[i] = ft_substr(line, 0, 0xffffffff);
		i += 1;
		if (*rows == i)
			*write = TRUE;
	}
}

char **open_file(char *file, char **res, int control, int *write)
{
	int fd;
	char *line;
	int static rows;

	if (!rows)
		rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_message(DANGER, MSG_DAN_3);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (!res)
				res = (char **)ft_calloc(rows + 1, sizeof(char *));
			control = TRUE;
			close(fd);
			if (*write)
				return (res);
			open_file(file, res, control, write);
		}
		else if (line)
			is_line(line, res, &rows, control, write);
		free(line);
	}
}

char **la_funcion(char *file)
{
	char **res = NULL;
	int control;
	int write;

	control = FALSE;
	write = FALSE;

	return (open_file(file, res, control, &write));
}

void free_cur(char **str)
{
	int i = 0;

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

	cur = la_funcion(file);

	int i = 0;
	if (cur)
	{
		while (cur[i])
		{
			ft_printf("%s\n", cur[i]);
			i++;
		}
	}
	free_cur(cur);
}

// gcc get_to_doble_ptr.c -g3 ../../sources/libft/libft.a
