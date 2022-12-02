/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/libft/inc/libft.h"
#include "../../sources/libft/inc/ft_printf.h"
#include "../../sources/libft/inc/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// esto esta PROHIBIDO por la norma
// es VLAs - Variable Length Arrays

#define ROWS 5
#define COLS 21

void file_to_map(char *line, char map[ROWS][COLS], int j)
{
	int i;

	i = 0;
	while (line[i] != '\n')
	{
		map[j][i] = line[i];
		i++;
	}
	map[j][i] = '\0';
}

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int i = 0;
	char map[ROWS][COLS];

	fd = open(argv[1], O_RDONLY);

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			line = get_next_line(fd);
			break;
		}
		else if (line)
		{
			file_to_map(line, map, i);
			ft_printf("%s", line);
			i++;
			if (line)
				free(line);
		}
	}
}

// void check(string (&temp2D)[100][100], string (&temp1D)[100]);
