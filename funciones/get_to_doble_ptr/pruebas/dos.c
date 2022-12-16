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

void static is_line(char *line, char **res, int *rows, int control)
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
	}
}

void open_file(char *file, char **res, int control)
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
	res = (char **)ft_calloc(rows + 1, sizeof(char *));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			control = TRUE;
			close(fd);
			break;
		}
		else if (line)
			is_line(line, res, &rows, control);
		free(line);
	}
}

// TIENE devolver el doble puntero y pasar el path del file
char **la_funcion(char *file)
{
	char **res = NULL;
	int control;

	control = FALSE;

	open_file(file, res, control);
	return (res);
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
}
