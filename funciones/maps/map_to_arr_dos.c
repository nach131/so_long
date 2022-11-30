/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
// ft_strdup

#include "../../sources/libft/inc/libft.h"
#include "../../sources/libft/inc/ft_printf.h"
#include "../../sources/libft/inc/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void file_to_map(char *line, char **map, int i)
{
}

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int i = 0;
	char **map;

	*map = ft_strdup("42 Barcelona");
	// map[1] = "42 Madrid";

	// fd = open(argv[1], O_RDONLY);
	fd = open("../../sources/maps/veinte.ber", O_RDONLY);

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
			file_to_map(line, &(*map), i);
			ft_printf("%s", line);
			i++;
			if (line)
				free(line);
		}
	}
}
