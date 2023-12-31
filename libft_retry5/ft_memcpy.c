/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:24:57 by npiyapan          #+#    #+#             */
/*   Updated: 2023/10/04 18:25:01 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_2;
	char	*src_2;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst_2 = (char *)dst;
	src_2 = (char *)src;
	while (i < n)
	{
		dst_2[i] = src_2[i];
		i++;
	}
	return (dst);
}
