/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:27:53 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/10 14:16:04 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_length(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

static char	*word_by_word(char const *str, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = 0;
	while (str[len_word] && str[len_word] != c)
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (0);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)

{
	char	**strings;
	int		i;

	i = 0;
	if (!str)
		return (0);
	strings = (char **)malloc(sizeof(char *)
			* (check_length(str, c) + 1));
	if (!strings)
		return (0);
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str != '\0')
		{
			strings[i] = word_by_word(str, c);
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	strings[i] = 0;
	return (strings);
}
/*
int	main(void)
{
	int	index;
	char	**split;
	char	**split1;

	printf("======== Test0 ========\n");
	split = ft_split("helloxworldx42", 'x');
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
	free (split);
	printf("======== Test1 ========\n");
	split1 = ft_split("xxxxhelloxworldx42", 'x');
	index = 0;
	while (split1[index])
	{
		printf("%s\n", split1[index]);
		index++;
	}
	free (split1);
	printf("======== Test2 ========\n");
	split1 = ft_split("xxxxhelloxworldx42xxx", 'x');
	index = 0;
	while (split1[index])
	{
		printf("%s\n", split1[index]);
		index++;
	}
	free (split1);
}*/