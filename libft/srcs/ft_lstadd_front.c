/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:26:16 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/12 16:57:13 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}
/*
int	main(void)
{
	t_list	*l = NULL;

	l = ft_lstnew((void*)1);
	ft_lstadd_front(&l, ft_lstnew((void*)2));
	printf("%s\n", l->content == (void*)2 ? "Y" : "N");
}*/
