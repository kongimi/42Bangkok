/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:44:31 by npiyapan          #+#    #+#             */
/*   Updated: 2023/08/29 21:01:42 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (!(*s))
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*
int	main(void)
{
	char s[] = "Test my skill bla bla bla";
	printf("==== Test1 ====\n");
	printf("find T : %s\n", strchr(s, 'T') == s ? "Y" : "N");
	printf("find T : %s\n", ft_strchr(s, 'T') == s ? "Y" : "N");
	printf("==== Test2 ====\n");
	printf("find l : %s\n", strchr(s, 'l') == s + 11 ? "Y" : "N");
	printf("find l : %s\n", ft_strchr(s, 'l') == s + 11 ? "Y" : "N");
	printf("==== Test3 ====\n");
	printf("find z : %s\n", strchr(s, 'z') == 0 ? "Y" : "N");
	printf("find z : %s\n", ft_strchr(s, 'z') == 0 ? "Y" : "N");
	printf("==== Test4 ====\n");
	printf("find 0 : %s\n", strchr(s, 0) == s + strlen(s) ? "Y" : "N");
	printf("find 0 : %s\n", ft_strchr(s, 0) == s + strlen(s) ? "Y" : "N");
	printf("==== Test5 ====\n");
	printf("find t + 256 : %s\n", strchr(s, 't' + 256) == s ? "Y" : "N");
	printf("find t + 256 : %s\n", ft_strchr(s, 't' + 256) == s ? "Y" : "N");
}*/
