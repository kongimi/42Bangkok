/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:17:12 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/02 14:57:36 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	i = 0;
	while ((s1_c[i] || s2_c[i]) && i < n)
	{
		if (s1_c[i] != s2_c[i])
			return (s1_c[i] - s2_c[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*s1 = "Test";
	char	*s2 = "Normal";
	printf("======= Test1 =======\n");
	printf("%d\n", strncmp("t", "", 0));
	printf("%d\n", ft_strncmp("t", "", 0));
	printf("======= Test2 =======\n");
	printf("%d\n", strncmp("1234", "1235", 3));
	printf("%d\n", ft_strncmp("1234", "1235", 3));
	printf("======= Test3 =======\n");
	printf("%d\n", strncmp("1234", "1235", 4));
	printf("%d\n", ft_strncmp("1234", "1235", 4));
	printf("======= Test4 =======\n");
	printf("%d\n", strncmp("1234", "1235", -1));
	printf("%d\n", ft_strncmp("1234", "1235", -1));
	printf("======= Test5 =======\n");
	printf("%d\n", strncmp("", "", 42));
	printf("%d\n", ft_strncmp("", "", 42));
	printf("======= Test6 =======\n");
	printf("%d\n", strncmp("TestMy", "TestMy", 42));
	printf("%d\n", ft_strncmp("TestMy", "TestMy", 42));
	printf("======= Test7 =======\n");
	printf("%d\n", strncmp("TestMy", "TestMY", 42));
	printf("%d\n", ft_strncmp("TestMy", "TestMY", 42));
	printf("======= Test8 =======\n");
	printf("%d\n", strncmp("TestMy", "Testmy", 42));
	printf("%d\n", ft_strncmp("TestMy", "Testmy", 42));
	printf("======= Test9 =======\n");
	printf("%d\n", strncmp("TestMy", "TestMyE", 42));
	printf("%d\n", ft_strncmp("TestMy", "TestMyE", 42));
	printf("======= Test10 =======\n");
	printf("%d\n", strncmp("TestMy", "TestM", 42));
	printf("%d\n", ft_strncmp("TestMy", "TestM", 42));
	printf("======= Test11 =======\n");
	printf("%d\n", strncmp("", "1", 0));
	printf("%d\n", ft_strncmp("", "1", 0));
	printf("======= Test12 =======\n");
	printf("%d\n", strncmp("1", "", 0));
	printf("%d\n", ft_strncmp("1", "", 0));
	printf("======= Test13 =======\n");
	printf("%d\n", strncmp("", "1", 1));
	printf("%d\n", ft_strncmp("", "1", 1));
	printf("======= Test14 =======\n");
	printf("%d\n", strncmp("1", "", 1));
	printf("%d\n", ft_strncmp("1", "", 1));
	printf("======= Test11 ==5====\n");
	printf("%d\n", strncmp("", "", 1));
	printf("%d\n", ft_strncmp("", "", 1));
}*/
