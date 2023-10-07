/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:24:06 by npiyapan          #+#    #+#             */
/*   Updated: 2023/10/04 18:24:11 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	dst = (unsigned char *)s;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (dst[i] == c)
			return ((void *)(dst + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	a[] = {1, 2, 3, 4};

	printf("%s\n", ft_memchr(a, 1, 1) == a ? "Y" : "N");
}*/
