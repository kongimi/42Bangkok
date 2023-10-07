/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:28:31 by npiyapan          #+#    #+#             */
/*   Updated: 2023/10/04 18:29:08 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_check_word(char const *str, char c)
{
	size_t	ans;
	size_t	i;

	i = 0;
	ans = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while ((str[i] != c) && (str[i] != 0))
			i++;
		if ((i > 0) && (str[i - 1] != c))
			ans++;
	}
	return (ans);
}

void	ft_free_mem(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free (res[i]);
		res[i] = NULL;
		i++;
	}
}

size_t	ft_find_start(char const *str, char c, size_t i)
{
	while (str[i] == c)
		i++;
	return (i);
}

int	ft_cut_word(char **res, char const *str, char c)
{
	size_t	i;
	size_t	start;
	char	**head;

	i = 0;
	start = 0;
	head = res;
	while (i < ft_strlen(str))
	{
		i = ft_find_start(str, c, i);
		start = i;
		while ((str[i] != c) && (str[i] != 0))
			i++;
		if ((i > 0) && (str[i - 1] != 0) && (start < i))
		{
			*res = ft_substr(str, start, i - start);
			if (*res == NULL)
			{
				ft_free_mem(head);
				return (1);
			}
			res++;
		}
	}
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	size_t	w_count;

	if (str == 0)
		return (NULL);
	w_count = ft_check_word(str, c);
	res = ft_calloc(sizeof(char *), w_count + 1);
	if (res == NULL)
		return (NULL);
	if (ft_cut_word(res, str, c))
	{
		free (res);
		res = 0;
	}
	return (res);
}
/*
int	main(void)
{
	char	*a = "CCCCABCDEFCCCCCCGHCCCC";
	char	*b = "ABCDEFCCCCCCGH";
	char	**res;
	size_t	i;

	i = 0;
	res = ft_split(a, 'C');
	while (res[i] != 0)
		printf("%s\n", res[i++]);
	ft_free_mem(res);
	free (res);
	
	i = 0;
	res = ft_split(b, 'C');
	while (res[i] != 0)
		printf("%s\n", res[i++]);
	ft_free_mem(res);
	free (res);

	i = 0;
	char	*splitme = strdup("--1-2--3---4----5-----42");
	res = ft_split(splitme, '-');
	while (res[i] != 0)
		printf("%s\n", res[i++]);
	ft_free_mem(res);
	free (res);
	
	i = 0;
	char	*splitme2 = strdup("hello!");
	res = ft_split(splitme2, ' ');
	while (res[i] != 0)
		printf("%s\n", res[i++]);
	ft_free_mem(res);
	free (res);
}*/
