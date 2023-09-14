/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:33:13 by npiyapan          #+#    #+#             */
/*   Updated: 2023/08/31 20:28:49 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && ((i + j) < len))
		{
			if (!needle[j + 1])
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (0);
}
// Test
/*int	main(void)
{
	char	haystack[30] = "aaabcabcd";
	char	needle[10] = "aabc";
	char	*empty = (char *)"";

	printf("======== Test1 ========\n");
	printf("%s\n", strnstr(haystack, needle, 0)); 
	printf("%s\n", ft_strnstr(haystack, needle, 0)); 
	printf("======== Test2 ========\n");
	printf("%s\n", strnstr(haystack, needle, -1)); 
	printf("%s\n", ft_strnstr(haystack, needle, -1));
	printf("======== Test3 ========\n");
	printf("%s\n", strnstr(haystack, "a", -1)); 
	printf("%s\n", ft_strnstr(haystack, "a", -1));
	printf("======== Test4 ========\n");
	printf("%s\n", strnstr(haystack, "c", -1)); 
	printf("%s\n", ft_strnstr(haystack, "c", -1));
	printf("======== Test5 ========\n");
	printf("%s\n", strnstr(empty, "", -1)); 
	printf("%s\n", ft_strnstr(empty, "", -1));
	printf("======== Test6 ========\n");
	printf("%s\n", strnstr(empty, "", 0)); 
	printf("%s\n", ft_strnstr(empty, "", 0));
	printf("======== Test7 ========\n");
	printf("%s\n", strnstr(empty, "coucou", -1)); 
	printf("%s\n", ft_strnstr(empty, "coucou", -1));
	printf("======== Test8 ========\n");
	printf("%s\n", strnstr(haystack, "aaabc", 5)); 
	printf("%s\n", ft_strnstr(haystack, "aaabc", 5));
	printf("======== Test9 ========\n");
	printf("%s\n", strnstr(empty, "12345", 5)); 
	printf("%s\n", ft_strnstr(empty, "12345", 5));
	printf("======== Test10 ========\n");
	printf("%s\n", strnstr(haystack, "abcd", 9)); 
	printf("%s\n", ft_strnstr(haystack, "abcd", 9));
	printf("======== Test11 ========\n");
	printf("%s\n", strnstr(haystack, "cd", 8)); 
	printf("%s\n", ft_strnstr(haystack, "cd", 8));
	printf("======== Test12 ========\n");
	printf("%s\n", strnstr(haystack, "a", 1)); 
	printf("%s\n", ft_strnstr(haystack, "a", 1));
	printf("======== Test13 ========\n");
	printf("%s\n", strnstr("1", "a", 1)); 
	printf("%s\n", ft_strnstr("1", "a", 1));
}*/
