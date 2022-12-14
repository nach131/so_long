/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_to_doble_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:29:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/14 15:23:14 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <fcntl.h>
#include "../../sources/libft/inc/error.h"
#include "../../sources/libft/inc/get_next_line.h"

#define MSG_DAN_0 "Error 0: Missing file"
#define MSG_DAN_1 "Error 1: Too many arguments"
#define MSG_DAN_3 "Error 3: File not found"

void err_file(int n, char *file)
{
	int len;

	if (n < 2)
	{
		ft_message(DANGER, MSG_DAN_0);
		exit(EXIT_FAILURE);
	}
	else if (n > 2)
	{
		ft_message(DANGER, MSG_DAN_1);
		exit(EXIT_FAILURE);
	}
}

void static is_line(char *line, char **res, int *rows, int control)
{
	if (control == FALSE)
	{
		// ctrl_map(&(*map), line);
		*rows += 1; // AQUI SUMO
	}
	// else
	// {
	// 	write_map(&(*map), line, *rows);
	// 	map->write = TRUE;
	// 	*rows += 1;
	// }
}

void open_file(char *file, char **res, int control)
{
	int fd;
	char *line;
	int rows;

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
			control = TRUE;
			close(fd);
			if (res) /// CUIDADO
				break;
			open_file(file, res, control);
		}
		else if (line)
			is_line(line, res, &rows, control);
			free(line);
	}
}

// TIENE devolver el doble puntero y pasar el path del file
int main(int argc, char **argv)
{
	char **res;
	int control;

	control = FALSE;

	// CUIDAD HAY QUE CAMBIAR LOS PARAMETROS A PASAR
	// POR EL PATH
	err_file(argc, argv[1]);
	open_file(argv[1], res, control);
}

// gcc get_to_doble_ptr.c -g3 ../../sources/libft/libft.a
