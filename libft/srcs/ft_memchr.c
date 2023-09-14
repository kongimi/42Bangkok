/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:58:12 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/05 22:03:53 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	dst = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (dst[i] == (unsigned char)(c))
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char    s[] = {0, 1, 2, 3, 4, 5};
    
    printf("======== Test1 ========\n");
    printf("%s\n", memchr(s, 0, 0) == NULL ? "Y" : "N");
    printf("%s\n", ft_memchr(s, 0, 0) == NULL ? "Y" : "N");
    printf("======== Test2 ========\n");
    printf("%s\n", memchr(s, 0, 1) == s ? "Y" : "N");
    printf("%s\n", ft_memchr(s, 0, 1) == s ? "Y" : "N");
    printf("======== Test3 ========\n");
    printf("%s\n", memchr(s, 2, 3) == s + 2 ? "Y" : "N");
    printf("%s\n", ft_memchr(s, 2, 3) == s + 2 ? "Y" : "N");
    printf("======== Test4 ========\n");
    printf("%s\n", memchr(s, 6, 6) == NULL ? "Y" : "N");
    printf("%s\n", ft_memchr(s, 6, 6) == NULL ? "Y" : "N");
    printf("======== Test5 ========\n");
    printf("%s\n", memchr(s, 2 + 256, 3) == s + 2 ? "Y" : "N");
    printf("%s\n", ft_memchr(s, 2 + 256, 3) == s + 2 ? "Y" : "N");
}*/
