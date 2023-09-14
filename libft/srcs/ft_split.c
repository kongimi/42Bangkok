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

char    **ft_init(int   n)
{
    char    **res;
    
    res = (char **) malloc(sizeof(char *) * (n + 1));
    return res;
}

char	**ft_split(char const *str, char c)
{
	char	**strings;
    int     j;

    j = 0;
	if (!str)
		return (0);
    strings = ft_init(check_length(str, c));
	if (!strings)
        return (0);
    while (*str != '\0')
    {
        while (*str == c)
            str++;
        if (*str != 0)
        {
            strings[j++] = ft_substr(str, 0, (ft_strchr(str, c) - str));
            if (ft_strchr(str, c) == NULL)
                break ;
            str = ft_strchr(str, c);
        }
    }
    strings[j] = 0;
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
}
*/
