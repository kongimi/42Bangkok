/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:24:05 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/05 18:18:03 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char	*s1 = "Test";
	char	*s2 = "MyChannel";
	char	*p;

	printf("======== Test1 ========\n");
	p = ft_strjoin("tripouille", "42");
	printf("%s\n", p);
	printf("%s\n", !ft_strncmp(p, "tripouille42", ft_strlen(p)) ? "Y" : "N"); 
	printf("p len = %zu\n", ft_strlen(p));
	printf("res len = %zu\n", strlen("tripouille") + strlen("42") + 1);
	free(p);
	printf("======== Test2 ========\n");
	p = ft_strjoin("", "42");
	printf("%s\n", p);
	free(p);
	printf("======== Test3 ========\n");
	p = ft_strjoin("42", "");
	printf("%s\n", p);
	free(p);
	printf("======== Test4 ========\n");
	p = ft_strjoin("", "");
	printf("%s\n", p);
	free(p);
}*/
