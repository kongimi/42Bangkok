/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:15:08 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/24 19:26:54 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_reverse(t_list_int **stackA, t_list_int **stackB, long index)
{
	t_do_rev	s;

	s.i = 0;
	s.tmp_a = *stackA;
	while (s.i < index)
	{
		s.tmp_a = s.tmp_a->next;
		s.i++;
	}
	s.times_a = ft_lstsize_int(stackA) - index;
	s.times_b = ft_lstsize_int(stackB) - s.tmp_a->target_node;
	s.i = 0;
	while (s.i < s.times_b)
	{
		reverse_rotate(stackA, 1, 0);
		reverse_rotate(stackB, 1, 0);
		printf("rrr\n");
		s.i++;
	}
	while (s.i < s.times_a)
	{
		reverse_rotate(stackA, 1, 1);
		s.i++;
	}
}

void	do_reverse2(t_list_int **stackA, t_list_int **stackB, long index)
{
	t_do_rev	s;

	s.i = 0;
	s.tmp_a = *stackA;
	while (s.i < index)
	{
		s.tmp_a = s.tmp_a->next;
		s.i++;
	}
	s.times_a = ft_lstsize_int(stackA) - index;
	s.times_b = ft_lstsize_int(stackB) - s.tmp_a->target_node;
	s.i = 0;
	while (s.i < s.times_a)
	{
		reverse_rotate(stackA, 1, 0);
		reverse_rotate(stackB, 1, 0);
		printf("rrr\n");
		s.i++;
	}
	while (s.i < s.times_b)
	{
		reverse_rotate(stackB, 1, 1);
		s.i++;
	}
}
