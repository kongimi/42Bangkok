/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:37:50 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/09 11:02:47 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_c;
	unsigned char		*dst_c;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	src_c = (const unsigned char *)src;
	dst_c = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		i++;
	}
	return (dst);
}
// Test
//int	main(void)
//{
//	char	src[] = {0, 0};
//	char	dst[100];
//	char	*res2;
//
//	memset(dst,'A', 100);
//	printf("Test ft_memcpy\nOriginal dst = %s\n", dst);
//	printf("================= test1 =================\n");
//	ft_memcpy(dst, "coucou", 0);
//	printf("ft_memcpy coucou : %s\n", dst[0] == 'A' ? "True" : "False");
//	memcpy(dst, "coucou", 0);
//	printf("memcpy coucou : %s\n", dst[0] == 'A' ? "True" : "False");
//	printf("================= test2 =================\n");
//	res2 = ft_memcpy(dst, NULL, 0);
//	printf("ft_memcpy NULL : %s\n", (res2 == dst) && 
//	(dst[0] == 'A') ? "True" : "False");
//	res2 = memcpy(dst, NULL, 0);
//	printf("memcpy NULL : %s\n", (res2 == dst) && 
//	(dst[0] == 'A') ? "True" : "False");
//	printf("================= test3 =================\n");
//	ft_memcpy(dst, src, 2);
//	printf("ft_memcpy 0,2 : %s\n", (dst[0] == 0) && 
//	(dst[1] == 0) && (dst[2] == 'A') ? "True" : "False");
//	memset(dst,'A', 100);
//	memcpy(dst, src, 2);
//	printf("memcpy 0,2 : %s\n", (dst[0] == 0) && 
//	(dst[1] == 0) && (dst[2] == 'A') ? "True" : "False");
//}
