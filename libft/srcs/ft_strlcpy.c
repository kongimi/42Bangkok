/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:53:17 by npiyapan          #+#    #+#             */
/*   Updated: 2023/08/31 20:36:09 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (!src && !dstsize)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize <= 0)
		return (src_len);
	while (src[i] && dstsize-- >= 2)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
// Test
/*
int	main(void)
{
    char	*src = "Happy";
	char	dst[10];
    size_t  n;

	memset(dst,'A', 10);
    //n = strlen(src);
    //strlcpy(dst, src, n);
    //printf("strlcpy : %s\n", dst);
    //memset(dst,'A', 10);
    printf("======== Test1 ========\n");
    printf("ret strlcpy : %zu\n", strlcpy(dst, src, 0));
    printf("data strlcpy : %s\n", dst);
    printf("ret ftstrlcpy : %zu\n", ft_strlcpy(dst, src, 0));
    printf("data ft_strlcpy : %s\n", dst);
    printf("======== Test2 ========\n");
    memset(dst,'A', 10);
    printf("ret strlcpy : %zu\n", strlcpy(dst, src, 1));
    printf("data strlcpy : %s\n", dst);
    printf("ret ftstrlcpy : %zu\n", ft_strlcpy(dst, src, 1));
    printf("data ft_strlcpy : %s\n", dst);
    printf("======== Test3 ========\n");
    memset(dst,'A', 10);
    printf("ret strlcpy : %zu\n", strlcpy(dst, src, 2));
    printf("data strlcpy : %s\n", dst);
    printf("ret ftstrlcpy : %zu\n", ft_strlcpy(dst, src, 2));
    printf("data ft_strlcpy : %s\n", dst);
    printf("======== Test4 ========\n");
    memset(dst,'A', 10);
    printf("ret ftstrlcpy : %zu\n", ft_strlcpy(dst, src, -1));
    printf("data ft_strlcpy : %s\n", dst);
    memset(dst,'A', 10);
    n = ft_strlcpy(dst, src, -1);
    printf("cmp data : %s\n", n == strlen(src) && 
    !strcmp(src, dst) && dst[strlen(src) + 1] == 'A' ? "OK" : "No");
    printf("======== Test5 ========\n");
    memset(dst,'A', 10);
    printf("ret strlcpy : %zu\n", strlcpy(dst, src, 5));
    printf("data strlcpy : %s\n", dst);
    printf("ret ftstrlcpy : %zu\n", ft_strlcpy(dst, src, 5));
    printf("data ft_strlcpy : %s\n", dst);
    memset(dst,'A', 10);
    n = ft_strlcpy(dst, src, 5);
    printf("ft_strlcpy5 : %s\n", n == strlen(src) && !memcmp(src, dst, 4) && 
    dst[4] == 0 ? "OK" : "No");
    memset(dst,'A', 10);
    n = ft_strlcpy(dst, src, 6);
    printf("ft_strlcpy6 : %s\n", n == strlen(src) && 
    !memcmp(src, dst, 6) ? "OK" : "No");
    memset(dst,'A', 10);
    n = ft_strlcpy(dst, src, 7);
    printf("ft_strlcpy7 : %s\n", n == strlen(src) && 
    !memcmp(src, dst, 6) ? "OK" : "No");
    memset(dst,'A', 10);
    n = ft_strlcpy(dst, "", 42);
    printf("ft_strlcpy8 : %s\n", n == 0 && !memcmp("", dst, 1) ? "OK" : "No");
    memset(dst,'A', 10);
    n = strlcpy(dst, "1", 0);
    printf("strlcpy9 : %s\n", n == 1 && dst[0] == 0 ? "OK" : "No");
    printf("strlcpy9 : %c\n", dst[0]);
    n = ft_strlcpy(dst, "1", 0);
    printf("ft_strlcpy9 : %s\n", n == 1 && dst[0] == 0 ? "OK" : "No");
    printf("ft_strlcpy9 : %c\n", dst[0]);
}*/
