/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:03:42 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/09 10:42:26 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	if (!(dst) && !(src))
		return (NULL);
	if (dst > src)
	{
		i = len;
		while (i-- != 0)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
//int	main(void)
//{
//	char	s[] = {65, 66, 67, 68, 69, 0, 45};
//	char	s1[] = {65, 66, 67, 68, 69, 0, 45};
//	char	s0[] = {0, 0, 0, 0, 0, 0, 0};
//	char	sCpy[] = {65, 66, 67, 68, 69, 0, 45};
//	char	sResult[] = {67, 68, 67, 68, 69, 0, 45};
//	char	sResult2[] = {67, 67, 68, 68, 69, 0, 45};
//	char	sResult3[] = {67, 68, 67, 68, 69, 0, 45};
//	char	sResult4[] = {67, 67, 68, 68, 69, 0, 45};
//
//	printf("======== test1 ==========\n");
//	printf("Result1 lib : %s\n", memmove(s0, s, 7) == s0 && 
//	!memcmp(s, s0, 7) ? "Y" : "N");
//	printf("Result1 me  : %s\n", ft_memmove(s0, s, 7) == s0 && 
//	!memcmp(s, s0, 7) ? "Y" : "N");
//	printf("======== test2 ==========\n");
//	printf("Result2 lib : %s\n", memmove(s, s + 2, 0) && 
//	!memcmp(s, sCpy, 7) ? "Y" : "N");
//	printf("Result2 me  : %s\n", ft_memmove(s1, s1 + 2, 0) && 
//	!memcmp(s1, sCpy, 7) ? "Y" : "N");
//	printf("======== test3 ==========\n");
//	printf("Result3 lib : %s\n", memmove(s, s + 2, 2) == s  && 
//	!memcmp(s, sResult, 7) ? "Y" : "N");
//	printf("Result3 me  : %s\n", ft_memmove(s1, s1 + 2, 2) == s1 && 
//	!memcmp(s1, sResult, 7) ? "Y" : "N");
//	printf("======== test4 ==========\n");
//	printf("Result4 lib : %s\n", ft_memmove(sResult + 1, sResult, 2) 
//	== sResult + 1 && 
//	!memcmp(sResult, sResult2, 7) ? "Y" : "N");
//	printf("Result4 me  : %s\n", ft_memmove(sResult3 + 1, sResult3, 2) 
//	== sResult3 + 1 && 
//	!memcmp(sResult3, sResult4, 7) ? "Y" : "N");
//}
