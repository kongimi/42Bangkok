/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:36:33 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/22 12:10:19 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_int	*ft_lstnew_int(int val)
{
	t_list_int	*new_lst;

	new_lst = (t_list_int *)malloc(sizeof(t_list_int));
	if (new_lst == NULL)
		return (NULL);
	new_lst->val = val;
	new_lst->index = -1;
	new_lst->target_node = -1;
	new_lst->diff_val = INT_MAX;
	new_lst->max_val_index = -1;
	new_lst->name = 'a';
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}

void	ft_lstadd_back_int(t_list_int **lst, t_list_int *new)
{
	t_list_int	*tmp;

	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp->next;
	}
}

int	ft_lstsize_int(t_list_int **st)
{
	size_t		i;
	t_list_int	*tmp;

	i = 0;
	tmp = *st;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	free_list(t_list_int *stack)
{
	t_list_int	*tmp;
	t_list_int	*head;

	if (stack)
	{
		head = stack;
		while (head->next)
		{
			tmp = head;
			head = head->next;
			free (tmp);
		}
		free (head);
	}
}

t_list_int	*ft_lstlast_int(t_list_int *lst)
{
	t_list_int	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node && node->next)
		node = node->next;
	return (node);
}
