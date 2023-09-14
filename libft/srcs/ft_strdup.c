/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:19:42 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/05 20:37:10 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char	*p;

	printf("======== Test1 ========\n");
	p = strdup((char *)"coucou");	printf("%s\n", p);	free(p);
	p = ft_strdup((char *)"coucou");	printf("%s\n", p);	free(p);
	printf("======== Test2 ========\n");
	p = strdup((char *)"");	printf("%s\n", p);	free(p);
	p = ft_strdup((char *)"");	printf("%s\n", p);	free(p);
}*/
