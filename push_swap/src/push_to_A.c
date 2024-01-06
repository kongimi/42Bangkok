/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_A.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:19:12 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/29 11:03:19 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_to_top_2(t_list_int **stack, long index, long size)
{
	t_list_int	*tmp;
	long		mean;

	tmp = *stack;
	mean = size / 2;
	if (index <= mean)
		rotate(stack, index, 1);
	else
		reverse_rotate(stack, size - index, 1);
}

void	check_diff(t_tmp *s)
{
	while (s->tmp_a)
	{
		if (s->tmp_a->val > s->tmp_b->val)
		{
			s->tmp_diff = s->tmp_a->val - s->tmp_b->val;
			if (s->tmp_diff < s->tmp_b->diff_val)
			{
				s->found = 1;
				s->tmp_b->diff_val = s->tmp_diff;
				s->tmp_b->target_node = s->tmp_a->index;
				if (s->tmp_diff == 1)
					break ;
			}
		}
		s->tmp_a = s->tmp_a->next;
	}
}

void	find_tar_node2(t_list_int **stack_a, t_list_int **stack_b, long min_ind)
{
	t_tmp	s;

	s.tmp_a = *stack_a;
	s.tmp_b = *stack_b;
	s.i = 0;
	while (s.tmp_b)
	{
		s.tmp_a = *stack_a;
		s.found = 0;
		s.tmp_diff = 0;
		s.tmp_b->diff_val = INT_MAX;
		s.tmp_b->index = s.i;
		check_diff(&s);
		if (!s.found)
			s.tmp_b->target_node = min_ind;
		s.tmp_b = s.tmp_b->next;
		s.i++;
	}
}

int	push_a_2(t_tmp *s, t_list_int **stack_a, t_list_int **stack_b)
{
	if (s->push_index)
		target_to_top(stack_b, s->push_index, s->size);
	if ((*stack_b)->target_node)
	{
		s->size_a = ft_lstsize_int(stack_a);
		target_to_top(stack_a, (*stack_b)->target_node, s->size_a);
	}
	s->size = push(stack_b, stack_a);
	return (s->size);
}

int	push_to_a(t_list_int **stack_a, t_list_int **stack_b, long *min_ind_a)
{
	t_tmp	s;

	set_push_b(&s, stack_a, stack_b);
	re_index(&s.tmp_a, &s.max_ind_a, min_ind_a);
	find_tar_node2(&s.tmp_a, &s.tmp_b, *min_ind_a);
	if (cal_cost(stack_b, stack_a, &s.push_index))
		s.size = push(stack_b, stack_a);
	else
	{
		if ((s.push_index == 1) && (*stack_b)->target_node == 1)
			ss(stack_b, stack_a);
		else
		{
			if (s.push_index)
				to_top(stack_b, stack_a, s.push_index);
			else
			{
				if ((*stack_b)->target_node)
					target_top_b(&s, stack_b, stack_a);
			}
			s.size = push(stack_b, stack_a);
		}
	}
	return (s.size);
}
