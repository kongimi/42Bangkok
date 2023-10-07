/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:19:53 by npiyapan          #+#    #+#             */
/*   Updated: 2023/10/04 18:20:05 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*a = NULL;

	a = ft_lstnew("a");
	ft_lstadd_front(&a, ft_lstnew("B"));
	printf("%s\n", a->content == "B" ? "Y" : "N");
	a = a->next;
	printf("%s\n", a->content == "a" ? "Y" : "N"); 
}*/
