/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:02:28 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/27 17:04:08 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set1(t_operate *s)
{
	s->i = 0;
	s->max_val = 0;
	s->min_val = LONG_MAX;
	s->tmp->max_val_index = 0;
}

void	set_calcost(t_tmp *s)
{
	if (s->tmp_a->direction == s->tmp_b->direction)
	{
		if (s->cost_a < s->cost_b)
			s->cost = s->cost_b;
		else
			s->cost = s->cost_a;
	}
	else
		s->cost = s->cost_a + s->cost_b;
}

void	move_index(t_tmp *s, long index)
{
	s->i = 0;
	while (s->i < index)
	{
		s->tmp_a = s->tmp_a->next;
		s->i++;
	}
	s->i = 0;
	while (s->i < s->tmp_a->target_node)
	{
		s->tmp_b = s->tmp_b->next;
		s->i++;
	}
}

void	set_s(t_tmp *s, t_list_int **stackA, t_list_int **stackB)
{
	s->tmp_a = *stackA;
	s->tmp_b = *stackB;
	s->size_a = ft_lstsize_int(stackA);
	s->size_b = ft_lstsize_int(stackB);
}

void	to_top(t_list_int **stackA, t_list_int **stackB, long index)
{
	t_tmp		s;

	set_s(&s, stackA, stackB);
	re_index(stackA, &s.max, &s.min);
	move_index(&s, index);
	if (s.tmp_a->direction == s.tmp_b->direction)
	{
		if (!s.tmp_a->direction)
			dual_rotate(stackA, stackB, index);
		else
			dual_reverse(stackA, stackB, index);
	}
	else
	{
		if (!s.tmp_a->direction)
		{
			rotate(stackA, index, 1);
			reverse_rotate(stackB, s.size_b - s.tmp_b->index, 1);
		}
		else
		{
			reverse_rotate(stackA, s.size_a - index, 1);
			rotate(stackB, s.tmp_b->index, 1);
		}
	}
}
