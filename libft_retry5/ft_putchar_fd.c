/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:26:37 by npiyapan          #+#    #+#             */
/*   Updated: 2023/10/04 18:26:46 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, (unsigned char *)&c, 1);
}
/*
int	main(void)
{
	int	fd;
	char	s[10] = {0};

	fd = open("kong", O_RDWR | O_CREAT);
	ft_putchar_fd('z', fd);
	printf("read = %zu\n", read(fd, s, 1));
	printf("s = %s\n", s);
	close (fd);
}*/
