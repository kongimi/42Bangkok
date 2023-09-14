/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:20:18 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/10 15:17:47 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_find_num_len(long n)
{
	size_t	num_len;

	num_len = 0;
	if (n < 0)
	{
		n = -n;
		num_len++;
	}
	while (n > 9)
	{
		n /= 10;
		num_len++;
	}
	return (num_len + 1);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	num_len;
	size_t	i;
	long	nb;

	nb = n;
	num_len = ft_find_num_len(n);
	res = malloc(sizeof(char) * (num_len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	if (nb < 0)
		nb = -nb;
	while (i < num_len)
	{
		res[num_len - i - 1] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
		res[0] = '-';
	res[num_len] = '\0';
	return (res);
}
/*
int	main(void)
{
	char	*s;

	s = ft_itoa(65);
	printf("%s\n", s);
	free (s);
	s = ft_itoa(0);
	printf("%s\n", s);
	free (s);
	s = ft_itoa(-65);
	printf("%s\n", s);
	free (s);
}*/
