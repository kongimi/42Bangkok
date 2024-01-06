/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:15:30 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/24 18:54:06 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_list(t_list_int **stack_a, t_list_int **stack_b)
{
	free_list(*stack_a);
	free_list(*stack_b);
}

void	target_top_b(t_tmp *s, t_list_int **stack_a, t_list_int **stack_b)
{
	s->size_b = ft_lstsize_int(stack_b);
	target_to_top(stack_b, (*stack_a)->target_node, s->size_b);
}

/* find nearest smaller */
void	check_diff_a(t_tmp *s, long maxIndex)
{
	while (s->tmp_b)
	{
		if (s->tmp_a->val > s->tmp_b->val)
		{
			s->tmp_diff = s->tmp_a->val - s->tmp_b->val;
			if (s->tmp_diff < s->tmp_a->diff_val)
			{
				s->found = 1;
				s->tmp_a->diff_val = s->tmp_diff;
				s->tmp_a->target_node = s->tmp_b->index;
				if (s->tmp_diff == 1)
					break ;
			}
		}
		s->tmp_b = s->tmp_b->next;
	}
	if (!s->found)
		s->tmp_a->target_node = maxIndex;
}

void	set_stack(t_list_int **stackA, t_list_int **stackB, t_rotate *s)
{
	s->tail_a->next = *stackA;
	*stackA = s->tail_a;
	s->tail_b->next = *stackB;
	*stackB = s->tail_b;
	s->n++;
}

void	print_target_node(t_list_int **stack)
{
	t_list_int	*tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("(%ld) = %d, \ttarget node = %ld, \tname %c,\
		 \tdirection = %d\n", \
		tmp->index, tmp->val, tmp->target_node, tmp->name, tmp->direction);
		tmp = tmp->next;
	}
	printf("\n");
}
