/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:48:37 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/23 16:50:04 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list_int **stack, int my_times, int print)
{
	int			n;
	t_list_int	*head;
	t_list_int	*tail;

	n = 0;
	while (n < my_times)
	{
		head = *stack;
		tail = ft_lstlast_int(head);
		*stack = (*stack)->next;
		head->next = NULL;
		tail->next = head;
		n++;
		if (print)
			print_operation("r", (*stack)->name);
	}
}

void	reverse_rotate(t_list_int **stack, int my_times, int print)
{
	int			n;
	t_list_int	*head;
	t_list_int	*tail;

	n = 0;
	while (n < my_times)
	{
		head = *stack;
		tail = ft_lstlast_int(head);
		while (head)
		{
			if (!head->next->next)
			{
				head->next = NULL;
				break ;
			}
			head = head->next;
		}
		tail->next = *stack;
		*stack = tail;
		n++;
		if (print)
			print_operation("rr", (*stack)->name);
	}
}

void	ss(t_list_int **stackA, t_list_int **stackB)
{
	swap(stackA, 0);
	swap(stackB, 0);
	printf("ss\n");
}

void	rotate_both(t_list_int **stackA, t_list_int **stackB, int my_times)
{
	int			n;
	t_list_int	*head_a;
	t_list_int	*tail_a;
	t_list_int	*head_b;
	t_list_int	*tail_b;

	n = 0;
	while (n < my_times)
	{
		head_a = *stackA;
		tail_a = ft_lstlast_int(head_a);
		*stackA = (*stackA)->next;
		head_a->next = NULL;
		tail_a->next = head_a;
		head_b = *stackB;
		tail_b = ft_lstlast_int(head_b);
		*stackB = (*stackB)->next;
		head_b->next = NULL;
		tail_b->next = head_b;
		n++;
		ft_printf("rr\n");
	}
}

void	re_rotate_b(t_list_int **stackA, t_list_int **stackB, int my_t)
{
	t_rotate	s;

	s.n = 0;
	while (s.n < my_t)
	{
		s.head_a = *stackA;
		s.tail_a = ft_lstlast_int(s.head_a);
		s.head_b = *stackB;
		s.tail_b = ft_lstlast_int(s.head_b);
		while (s.head_a)
		{
			if (!s.head_a->next->next)
			{
				s.head_a->next = NULL;
				s.head_b->next = NULL;
				break ;
			}
			s.head_a = s.head_a->next;
			s.head_b = s.head_b->next;
		}
		set_stack(stackA, stackB, &s);
		ft_printf("rrr\n");
	}
}
