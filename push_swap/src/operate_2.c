/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:53:47 by npiyapan          #+#    #+#             */
/*   Updated: 2024/01/03 14:44:55 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_to_top(t_list_int **stack, long index, long size)
{
	t_list_int	*tmp;
	long		mean;
	long		size_a;

	tmp = *stack;
	size_a = ft_lstsize_int(stack);
	mean = size / 2;
	mean = size_a / 2;
	if (index <= mean)
		rotate(stack, index, 1);
	else
		reverse_rotate(stack, size_a - index, 1);
}

void	dual_reverse(t_list_int **stackA, t_list_int **stackB, long index)
{
	t_list_int	*tmp_a;
	long		i;
	long		times_a;
	long		times_b;

	tmp_a = *stackA;
	i = 0;
	while (i < index)
	{
		tmp_a = tmp_a->next;
		i++;
	}
	times_a = ft_lstsize_int(stackA) - index;
	times_b = ft_lstsize_int(stackB) - tmp_a->target_node;
	if (times_a > times_b)
		do_reverse(stackA, stackB, index);
	else
		do_reverse2(stackA, stackB, index);
}

int	push_to_b(t_list_int **stack_a, t_list_int **stack_b, long *max_ind_b)
{
	t_tmp		s;

	set_push_b(&s, stack_a, stack_b);
	re_index(stack_b, max_ind_b, &s.min_ind_b);
	find_tar_node(stack_a, stack_b, *max_ind_b);
	if (cal_cost(stack_a, stack_b, &s.push_index))
		s.size = push(stack_a, stack_b);
	else
	{
		if ((s.push_index == 1) && (*stack_a)->target_node == 1)
			ss(stack_a, stack_b);
		else
		{
			if (s.push_index)
				to_top(stack_a, stack_b, s.push_index);
			else
			{
				if ((*stack_a)->target_node)
					target_top_b(&s, stack_a, stack_b);
			}
			s.size = push(stack_a, stack_b);
		}
	}
	return (s.size);
}

void	find_min_index(t_list_int **stack_a, long *index)
{
	long		min_val;
	long		n;
	t_list_int	*tmp_a;

	tmp_a = *stack_a;
	min_val = LONG_MAX;
	*index = 0;
	n = 0;
	while (tmp_a->next)
	{
		if (min_val > tmp_a->next->val)
		{
			min_val = tmp_a->next->val;
			*index = n + 1;
		}
		tmp_a = tmp_a->next;
		n++;
	}
}

void	min_to_top(t_list_int **stack, long index)
{
	t_list_int	*tmp;
	int			mean;
	int			size;

	tmp = *stack;
	size = ft_lstsize_int(&tmp);
	mean = size / 2;
	if (index < mean)
	{
		if (index == 0)
			index = 1;
		rotate(stack, index, 1);
	}
	else
		reverse_rotate(stack, size - index, 1);
}
