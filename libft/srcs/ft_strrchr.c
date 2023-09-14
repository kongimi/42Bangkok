/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:02:13 by npiyapan          #+#    #+#             */
/*   Updated: 2023/08/29 22:04:09 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)s + len);
	while (len)
	{
		if (s[--len] == (unsigned char)c)
			return ((char *)s + len);
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*s = "Test my skill";
	char	s3[] = "";
	char	*empty = (char*)calloc(1,1);

	printf("==== Test1 ====\n");
	printf("find T : %s\n", strrchr(s, 'T') == s ? "Y" : "N");
	printf("find T : %s\n", ft_strrchr(s, 'T') == s ? "Y" : "N");
	printf("==== Test2 ====\n");
	printf("find l : %s\n", strrchr(s, 'l') == s + 12 ? "Y" : "N");
	printf("find l : %s\n", ft_strrchr(s, 'l') == s + 12 ? "Y" : "N");
	printf("==== Test3 ====\n");
	printf("find z : %s\n", strrchr(s, 'z') == NULL ? "Y" : "N");
	printf("find z : %s\n", ft_strrchr(s, 'z') == NULL ? "Y" : "N");
	printf("==== Test4 ====\n");
	printf("find 0 : %s\n", strrchr(s, 0) == s + ft_strlen(s) ? "Y" : "N");
	printf("find 0 : %s\n", ft_strrchr(s, 0) == s + ft_strlen(s) ? "Y" : "N");
	printf("==== Test5 ====\n");
	printf("find t + 256 : %s\n", strrchr(s, 'T' + 256) == s ? "Y" : "N");
	printf("find t + 256 : %s\n", ft_strrchr(s, 'T' + 256) == s ? "Y" : "N");
	printf("==== Test6 ====\n");
	printf("find empty : %s\n", strrchr(empty, 's') == NULL ? "Y" : "N");
	printf("find empty : %s\n", ft_strrchr(empty, 's') == NULL ? "Y" : "N");
	printf("find empty : %s\n", strrchr(empty, 's'));
	printf("==== Test7 ====\n");
	printf("find 0 in "" : %s\n", strrchr(s3, 0) == s3 ? "Y" : "N");
	printf("find 0 in "" : %s\n", ft_strrchr(s3, 0) == s3 ? "Y" : "N");
}*/
