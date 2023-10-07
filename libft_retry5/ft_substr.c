/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:35:03 by npiyapan          #+#    #+#             */
/*   Updated: 2023/10/04 18:35:07 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		start = ft_strlen(s);
		len = 0;
	}
	else if ((start + len) >= ft_strlen(s))
		len = ft_strlen(s) - start;
	res = ft_calloc(sizeof(char), len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
/*
int	main(void)
{
	char	*s = "ABCDEFGHI";
	char	*a;

	a = ft_substr(s, 2, 4);
	printf("%s\n", a);
	free (a);

	a = ft_substr(s, 10, 4);
	printf("%s\n", a);
	free (a);
	
	a = ft_substr(s, 0, 20);
	printf("%s\n", a);
	free (a);
}*/
