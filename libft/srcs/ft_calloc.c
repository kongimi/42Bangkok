/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:25:30 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/02 14:16:10 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
int	main(void)
{
	void	* p = ft_calloc(2,2);
	char	e[] = {0, 0, 0, 0};

	printf("======== Test1 ========\n");
	printf("memcmp : %d\n", memcmp(p, e, 4));
	printf("ft_memcmp : %d\n", ft_memcmp(p, e, 4));
	free(p);
	printf("======== Test3 ========\n");
	printf("SIZE_MAX : %s\n", calloc(SIZE_MAX, SIZE_MAX) == NULL ? "Y" : "N");
	printf("SIZE_MAX : %s\n", ft_calloc(SIZE_MAX, SIZE_MAX) == NULL ? "Y" : "N");
	printf("======== Test4 ========\n");
	printf("SIZE_MAX : %s\n", calloc(INT_MAX, INT_MAX) == NULL ? "Y" : "N");
	printf("SIZE_MAX : %s\n", ft_calloc(INT_MAX, INT_MAX) == NULL ? "Y" : "N");
	printf("======== Test5 ========\n");
	printf("SIZE_MAX : %s\n", calloc(INT_MIN, INT_MIN) == NULL ? "Y" : "N");
	printf("SIZE_MAX : %s\n", ft_calloc(INT_MIN, INT_MIN) == NULL ? "Y" : "N");
	printf("======== Test6 ========\n");
	p = calloc(0, 0);
	printf("0,0 : %s\n", p != NULL ? "Y" : "N");	free(p);
	p = ft_calloc(0, 0);
	printf("0,0 : %s\n", p != NULL ? "Y" : "N");	free(p);
	printf("======== Test7 ========\n");
	p = calloc(0, 5);
	printf("0,5 : %s\n", p != NULL ? "Y" : "N");	free(p);
	p = ft_calloc(0, 5);
	printf("0,5 : %s\n", p != NULL ? "Y" : "N");	free(p);
	printf("======== Test8 ========\n");
	p = calloc(5, 0);
	printf("5,0 : %s\n", p != NULL ? "Y" : "N");	free(p);
	p = ft_calloc(5, 0);
	printf("5,0 : %s\n", p != NULL ? "Y" : "N");	free(p);
	printf("======== Test9 ========\n");
	p = calloc(-5, -5);
	printf("-5,-5 : %s\n", p == NULL ? "Y" : "N");	free(p);
	p = ft_calloc(-5, -5);
	printf("-5,-5 : %s\n", p == NULL ? "Y" : "N");	free(p);
	printf("======== Test10 ========\n");
	p = calloc(0, -5);
	printf("0,-5 : %s\n", p != NULL ? "Y" : "N");	free(p);
	p = ft_calloc(0, -5);
	printf("0,-5 : %s\n", p != NULL ? "Y" : "N");	free(p);
	printf("======== Test11 ========\n");
	p = calloc(-5, 0);
	printf("-5,0 : %s\n", p != NULL ? "Y" : "N");	free(p);
	p = ft_calloc(-5, 0);
	printf("-5,0 : %s\n", p != NULL ? "Y" : "N");	free(p);
	printf("======== Test12 ========\n");
	p = calloc(3, -5);
	printf("3, -5 : %s\n", p == NULL ? "Y" : "N");	free(p);
	p = ft_calloc(3, -5);
	printf("3, -5 : %s\n", p == NULL ? "Y" : "N");	free(p);
	printf("======== Test13 ========\n");
	p = calloc(-5, 3);
	printf("-5, 3 : %s\n", p == NULL ? "Y" : "N");	free(p);
	p = ft_calloc(-5, 3);
	printf("-5, 3 : %s\n", p == NULL ? "Y" : "N");	free(p);
}
*/