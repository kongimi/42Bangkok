/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:18:05 by npiyapan          #+#    #+#             */
/*   Updated: 2023/10/20 23:06:47 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	// int		fd2;
	char	*line;

	fd = open("41_with_nl", O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("address = %p\n", line);
		printf("ans = %s", line);
		printf("free line = %p\n", line);
		free (line);
		printf("====================================\n");
	}
	close (fd);

	// fd = open("test.txt", O_RDONLY);

	// line = get_next_line(fd);
	// if (line)
	// {
	// 	printf("ans = %s", line);
	// 	printf("free line = %p\n", line);
	// 	free (line);
	// }
	// printf("====================================\n");

	// line = get_next_line(fd);
	// if (line)
	// {
	// 	printf("ans = %s", line);
	// 	printf("free line = %p\n", line);
	// 	free (line);
	// }
	// printf("====================================\n");
	
	// line = get_next_line(fd);
	// if (line)
	// {
	// 	printf("ans = %s", line);
	// 	printf("free line = %p\n", line);
	// 	free (line);
	// }
	// printf("====================================\n");

	// line = get_next_line(fd);
	// if (line)
	// {
	// 	printf("ans = %s", line);
	// 	printf("free line = %p\n", line);
	// 	free (line);
	// }
	// close (fd);
	// printf("====================================\n");
	// line = NULL;
	// printf("%s", line);
	// printf("test2 = %lu\n", ft_strlen(""));
	return (0);
}
