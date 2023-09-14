/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:11:24 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/05 20:58:38 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ptr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		start = s_len;
		len = 0;
	}
	else if (len >= s_len - start)
	{
		len = s_len - start;
	}
	ptr = (char *) malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
/*
int	main(void)
{
	char	*s = "ABCDEFGHIJK";
	char	*p;

	printf("%s\n", s);
	printf("======== Test1 ========\n");
	p = ft_substr(s, 3, 3);
	printf("3,3 res : %s\n", p);	free(p);
	printf("======== Test2 ========\n");
	p = ft_substr(s, 9, 3);
	printf("9,3 res : %s\n", p);	free(p);
	printf("======== Test3 ========\n");
	p = ft_substr(s, 10, 3);
	printf("10,3res : %s\n", p);	free(p);
	printf("======== Test4 ========\n");
	p = ft_substr(s, 11, 3);
	printf("11,3 res : %s\n", p);	free(p);
	printf("======== Test5 ========\n");
	p = ft_substr(NULL, 3, 3);
	printf("s=NULL res : %s\n", p);	free(p);
	printf("======== Test6 ========\n");
	p = ft_substr(s, 3, 0);
	printf("res : %s\n", p);	free(p);
}*/
