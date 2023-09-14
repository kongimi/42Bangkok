/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:07:02 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/12 15:24:37 by npiyapan         ###   ########.fr       */
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
	int	fd = open("kong", O_RDWR | O_CREAT);

	ft_putchar_fd('a', fd);
}*/
