/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:47:36 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/05 20:47:58 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match_c(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	begin;
	size_t	end;
	char	*s2;

	i = 0;
	begin = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[begin] && match_c(set, s1[begin]))
		begin++;
	while (end > begin && match_c(set, s1[end - 1]))
		end--;
	s2 = malloc(sizeof(char) * (end - begin + 1));
	if (s2 == NULL)
		return (NULL);
	while (begin < end)
		s2[i++] = s1[begin++];
	s2[i] = '\0';
	return (s2);
}
/*
int	main(void)
{
	char	*s1 = "TestTestABCD";
	char	*s2 = "12";

	printf("%s\n", ft_strtrim(s1, s2));
	// s3 = ft_strnstr(s1, s2, ft_strlen(s1));
	// printf("%s", s3);
}*/
