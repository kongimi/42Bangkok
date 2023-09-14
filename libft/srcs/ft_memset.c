/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:37:44 by npiyapan          #+#    #+#             */
/*   Updated: 2023/08/31 18:25:09 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

//Test
/*int	main(void)
{
	char	arr[69] = "COCK";
	printf("inp: %s\n", arr);
	ft_memset(arr, '0', sizeof(arr));
	printf("ret: %s\n", arr);
	return (0);
}*/
