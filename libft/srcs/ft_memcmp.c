/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:57:17 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/02 12:22:32 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	s1_c = (unsigned char *)(s1);
	s2_c = (unsigned char *)(s2);
	i = 0;
	while (i < n)
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
	printf("======== Test1 ========\n");
	printf("%d\n", memcmp("t", "", 0));
	printf("%d\n", ft_memcmp("t", "", 0));
	printf("======== Test2 ========\n");
	printf("%d\n", memcmp("1234", "1235", 3));
	printf("%d\n", ft_memcmp("1234", "1235", 3));
	printf("======== Test3 ========\n");
	printf("%d\n", memcmp("1234", "1235", 4));
	printf("%d\n", ft_memcmp("1234", "1235", 4));
	printf("======== Test4 ========\n");
	printf("%d\n", memcmp("1234", "1235", -1));
	printf("%d\n", ft_memcmp("1234", "1235", -1));
	printf("======== Test5 ========\n");
	printf("%d\n", memcmp("", "", 42));
	printf("%d\n", ft_memcmp("", "", 42));
	printf("======== Test6 ========\n");
	printf("%d\n", memcmp("Tripouille", "Tripouille", 42));
	printf("%d\n", ft_memcmp("Tripouille", "Tripouille", 42));
	printf("======== Test7 ========\n");
	printf("%d\n", memcmp("Tripouille", "tripouille", 42));
	printf("%d\n", ft_memcmp("Tripouille", "tripouille", 42));
	printf("======== Test8 ========\n");
	printf("%d\n", memcmp("Tripouille", "TriPouille", 42));
	printf("%d\n", ft_memcmp("Tripouille", "TriPouille", 42));
	printf("======== Test9 ========\n");
	printf("%d\n", memcmp("Tripouille", "TripouillE", 42));
	printf("%d\n", ft_memcmp("Tripouille", "TripouillE", 42));
	printf("======== Test10 ========\n");
	printf("%d\n", memcmp("Tripouille", "TripouilleX", 42));
	printf("%d\n", ft_memcmp("Tripouille", "TripouilleX", 42));
	printf("======== Test11 ========\n");
	printf("%d\n", memcmp("Tripouille", "Tripouill", 42));
	printf("%d\n", ft_memcmp("Tripouille", "Tripouill", 42));
	printf("======== Test12 ========\n");
	printf("%d\n", memcmp("", "1", 0));
	printf("%d\n", ft_memcmp("", "1", 0));
	printf("======== Test13 ========\n");
	printf("%d\n", memcmp("1", "", 0));
	printf("%d\n", ft_memcmp("1", "", 0));
	printf("======== Test14 ========\n");
	printf("%d\n", memcmp("", "1", 1));
	printf("%d\n", ft_memcmp("", "1", 1));
	printf("======== Test15 ========\n");
	printf("%d\n", memcmp("1", "", 1));
	printf("%d\n", ft_memcmp("1", "", 1));
	printf("======== Test16 ========\n");
	printf("%d\n", memcmp("", "", 1));
	printf("%d\n", ft_memcmp("", "", 1));
}*/
