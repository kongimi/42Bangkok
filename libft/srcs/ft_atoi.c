/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:33:37 by npiyapan          #+#    #+#             */
/*   Updated: 2023/08/31 21:39:42 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	flow_ret(int neg)
{
	if (neg == 1)
		return ('7');
	else
		return ('8');
}

static int	strtol_ret(int neg)
{
	if (neg == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	t_ul	res;
	int		mul;
	int		i;
	int		lim;

	i = 0;
	res = 0;
	mul = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			mul = -1;
	lim = flow_ret(mul);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > SIZE_MAX) || (res == SIZE_MAX && (str[i] > lim)))
			return (strtol_ret(mul));
		res = (res * 10) + str[i++] - '0';
	}
	return (res * mul);
}
/*
int	main(void)
{
	//char	escape[] = {9, 10, 11, 12, 13, 0};
	//string	e(escape);
	printf("======== Test1 ========\n");
	printf("res : %d\n", atoi("1"));
	printf("res : %d\n", ft_atoi("1"));
	printf("======== Test2 ========\n");
	printf("res : %d\n", atoi("a1"));
	printf("res : %d\n", ft_atoi("a1"));
	printf("======== Test3 ========\n");
	printf("res : %d\n", atoi("--1"));
	printf("res : %d\n", ft_atoi("--1"));
	printf("======== Test4 ========\n");
	printf("res : %d\n", atoi("++1"));
	printf("res : %d\n", ft_atoi("++1"));
	printf("======== Test5 ========\n");
	printf("res : %d\n", atoi("+1"));
	printf("res : %d\n", ft_atoi("+1"));
	printf("======== Test6 ========\n");
	printf("res : %d\n", atoi("-1"));
	printf("res : %d\n", ft_atoi("-1"));
	printf("======== Test7 ========\n");
	printf("res : %d\n", atoi("0"));
	printf("res : %d\n", ft_atoi("0"));
	printf("======== Test8 ========\n");
	printf("res : %d\n", atoi("+42lon"));
	printf("res : %d\n", ft_atoi("+42lon"));
	printf("======== Test9 ========\n");
	printf("res : %d\n", atoi("+101"));
	printf("res : %d\n", ft_atoi("+101"));
}*/
