/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:57:13 by npiyapan          #+#    #+#             */
/*   Updated: 2023/09/12 16:10:34 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	if (new_lst)
	{
		new_lst->content = content;
		new_lst->next = NULL;
	}
	return (new_lst);
}
/*
int	main(void)
{
	t_list	*l = ft_lstnew((void*)42);
	printf("%s\n", l->content == (void*)42 ? "Y": "N");
	printf("%s\n", l->next == 0 ? "Y": "N");
	free (l);
}*/
