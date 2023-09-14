/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:09:23 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/05 20:32:28 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	while (src[i] != '\0' && (dst_len + i < (dstsize - 1)))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
// Test
/*
int	main(void)
{
    char	*src = "AAAAAAAAA";
    char	dst[30];
    size_t  n;

    printf("======== Test1 ========\n");
    memset(dst, 0, 30);
    dst[0] = 'B';
    printf("n = %zu\n%s\n", strlcat(dst, src, 0), dst);
    memset(dst, 0, 30);
    dst[0] = 'B';
    printf("n = %zu\n%s\n", ft_strlcat(dst, src, 0), dst);
    printf("======== Test2 ========\n");
    memset(dst, 0, 30);
    dst[0] = 'B';
    printf("n = %zu\n%s\n", strlcat(dst, src, 1), dst);
    memset(dst, 0, 30);
    dst[0] = 'B';
    printf("n = %zu\n%s\n", ft_strlcat(dst, src, 1), dst);
    printf("======== Test3 ========\n");
    memset(dst, 'B', 4);
    printf("n = %zu\n%s\n", strlcat(dst, src, 3), dst);
    memset(dst, 'B', 4);
    printf("n = %zu\n%s\n", ft_strlcat(dst, src, 3), dst);
    printf("======== Test4 ========\n");
    memset(dst, 'B', 4);
    printf("n = %zu\n%s\n", strlcat(dst, src, 6), dst);
    memset(dst, 'B', 4);
    printf("n = %zu\n%s\n", ft_strlcat(dst, src, 6), dst);
    printf("======== Test5 ========\n");
    memset(dst, 'C', 5);
    printf("n = %zu\n%s\n", ft_strlcat(dst, src, -1), dst);
    printf("======== Test6 ========\n");
    memset(dst, 'C', 15);
    printf("n = %zu\n%s\n", strlcat(dst, src, 17), dst);
    memset(dst, 'C', 15);
    printf("n = %zu\n%s\n", ft_strlcat(dst, src, 17), dst);
    printf("======== Test7 ========\n");
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", strlcat(dst, src, 1), dst);
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", ft_strlcat(dst, src, 1), dst);
    printf("======== Test8 ========\n");
    memset(dst, 0, 30); memset(dst, '1', 10);
    printf("n = %zu\n%s\n", strlcat(dst, src, 5), dst);
    memset(dst, 0, 30); memset(dst, '1', 10);
    printf("n = %zu\n%s\n", ft_strlcat(dst, src, 5), dst);
    printf("======== Test10 ========\n");
    memset(dst, 0, 30); memset(dst, '1', 10);
    printf("n = %zu\n%s\n", strlcat(dst, "", 15), dst);
    memset(dst, 0, 30); memset(dst, '1', 10);
    printf("n = %zu\n%s\n", ft_strlcat(dst, "", 15), dst);
    printf("======== Test11 ========\n");
    memset(dst, 0, 30); memset(dst, '1', 10);
    printf("n = %zu\n%s\n", ft_strlcat(dst, "", 42), dst);
    printf("======== Test12 ========\n");
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", strlcat(dst, "", 0), dst);
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", ft_strlcat(dst, "", 0), dst);
    printf("======== Test13 ========\n");
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", strlcat(dst, "123", 1), dst);
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", ft_strlcat(dst, "123", 1), dst);
    printf("======== Test14 ========\n");
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", strlcat(dst, "123", 2), dst);
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", ft_strlcat(dst, "123", 2), dst);
    printf("======== Test15 ========\n");
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", strlcat(dst, "123", 3), dst);
    memset(dst, 0, 30);
    printf("n = %zu\n%s\n", ft_strlcat(dst, "123", 3), dst);
}*/
