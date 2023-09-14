/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:36:08 by npiyapan          #+#    #+#             */
/*   Updated: 2023/08/29 20:44:01 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
int	main(void)
{
	printf("====== test1 =====\n");
	printf("A - 1 : %s\n", ft_tolower('A' - 1) == 'A' - 1 ? "y" : "n");
	printf("====== test2 =====\n");
	printf("A : %s\n", ft_tolower('A') == 'a' ? "y" : "n");
	printf("====== test3 =====\n");
	printf("Z + 1 : %s\n", ft_tolower('Z' + 1) == 'Z' + 1 ? "y" : "n");
	printf("====== test4 =====\n");
	printf("Z : %s\n", ft_tolower('Z') == 'z' ? "y" : "n");
}*/
