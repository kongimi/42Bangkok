/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:43:12 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/23 16:51:49 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_index(t_list_int **stackA, long *ind)
{
	long		max_val;
	long		n;
	t_list_int	*tmp_a;

	tmp_a = *stackA;
	max_val = tmp_a->val;
	*ind = 0;
	n = 0;
	while (tmp_a->next)
	{
		if (max_val < tmp_a->next->val)
		{
			max_val = tmp_a->next->val;
			*ind = n + 1;
		}
		tmp_a = tmp_a->next;
		n++;
	}
}

void	max_to_bottom(t_list_int **stack, long ind)
{
	t_list_int	*tmp;
	int			mean;
	int			size;

	tmp = *stack;
	size = ft_lstsize_int(&tmp);
	mean = size / 2;
	if (ind != (size - 1))
	{
		if (ind < mean)
		{
			if (ind == 0)
				ind = 1;
			rotate(stack, ind, 1);
		}
		else
		{
			if (ind == 0)
				ind = 1;
			reverse_rotate(stack, ind, 1);
		}
	}
}

void	sort_three(t_list_int **stackA)
{
	long		ind;

	find_index(stackA, &ind);
	max_to_bottom(stackA, ind);
	if ((*stackA)->val > (*stackA)->next->val)
		swap(stackA, 1);
}
