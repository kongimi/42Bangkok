/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:23:37 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/12 19:40:05 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *st)
{
	size_t	size;
	t_list	*node;

	size = 0;
	node = st;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}
/*
void	freeList(t_list *head)
{
	if (head)
	{
		freeList((t_list *)head->next);
		free (head);
	}
}

int	main(void)
{
	t_list	*l = NULL;

	 l =ft_lstnew((void *)1);
	printf("%s\n", l->content == (void *)1 ? "Y" : "N");
	printf("%s\n", ft_lstsize(l) == 1 ? "Y" : "N");
	ft_lstadd_front(&l, ft_lstnew((void *)2));
	printf("%s\n", ft_lstsize(l) == 2 ? "Y" : "N");
	freeList(l);
}*/
