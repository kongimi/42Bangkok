/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:06:00 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/24 19:11:16 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	node_to_top(t_list_int **stack, int index, int size)
{
	t_list_int	*tmp;
	int			mean;
	long		cost;

	tmp = *stack;
	mean = size / 2;
	cost = 0;
	if (index <= mean)
		cost = index;
	else
		cost = size - index;
	return (cost);
}

int	cal_cost(t_list_int **stackA, t_list_int **stackB, long *target_index)
{
	t_tmp	s;

	s.tmp_a = *stackA;
	s.tmp_b = *stackB;
	s.cost = 0;
	s.min_cost = LONG_MAX;
	s.size = ft_lstsize_int(&s.tmp_a);
	while (s.tmp_a)
	{
		s.cost_a = node_to_top(&s.tmp_a, s.tmp_a->index, s.size);
		s.size_b = ft_lstsize_int(&s.tmp_b);
		s.cost_b = node_to_top(&s.tmp_b, s.tmp_a->target_node, s.size_b);
		s.tmp_c = s.tmp_b->index + s.tmp_a->target_node;
		set_calcost(&s);
		if (s.cost < s.min_cost)
		{
			s.min_cost = s.cost;
			*target_index = s.tmp_a->index;
			if (s.cost == 0)
				return (1);
		}
		s.tmp_a = s.tmp_a->next;
	}
	return (0);
}

// int	cal_cost(t_list_int **stackA, t_list_int **stackB, long *target_index)
// {
// 	t_tmp	s;

// 	s.tmp_a = *stackA;
// 	s.tmp_b = *stackB;
// 	s.cost = 0;
// 	s.min_cost = LONG_MAX;
// 	s.size = ft_lstsize_int(&s.tmp_a);
// 	while (s.tmp_a)
// 	{
// 		s.cost = node_to_top(&s.tmp_a, s.tmp_a->index, s.size);
// 		if (s.tmp_a->index != s.tmp_a->target_node)
// 		{
// 			s.size_b = ft_lstsize_int(&s.tmp_b);
// 			s.cost += node_to_top(&s.tmp_b, s.tmp_a->target_node, s.size_b);
// 		}
// 		if (s.cost < s.min_cost)
// 		{
// 			s.min_cost = s.cost;
// 			*target_index = s.tmp_a->index;
// 			if (s.cost == 0)
// 				return (1);
// 		}
// 		s.tmp_a = s.tmp_a->next;
// 	}
// 	return (0);
// }
