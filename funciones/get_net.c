/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_net.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:26:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/06 23:34:57 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../sources/libft/inc/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("../sources/maps/veinte.ber", O_RDONLY);
// 	// close(fd);

// 	// if (fd == -1)
// 	// 	return (-1);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 		{
// 			line = get_next_line(fd);
// 			close(fd);
// 			break;
// 		}
// 		else if (line)
// 		{
// 			printf("%s", line);
// 			// printf("----------------\n");
// 			// if (line)
// 			line = NULL;
// 			free(line);
// 		}
// 	}
// 	return (1);
// }

int main(void)
{
	int fd;
	char *line;

	fd = open("../sources/maps/veinte.ber", O_RDONLY);
	// printf("main fd = %d\n", fd);
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
