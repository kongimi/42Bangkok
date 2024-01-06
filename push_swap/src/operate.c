/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:36:54 by npiyapan          #+#    #+#             */
/*   Updated: 2024/01/03 15:33:40 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list_int **src, t_list_int **dest)
{
	t_list_int	*tmp;

	if (!(*src))
		return (-1);
	tmp = *src;
	*src = (*src)->next;
	if (tmp->name == 'a')
		tmp->name = 'b';
	else
		tmp->name = 'a';
	if (!(*dest))
	{
		tmp->next = NULL;
		tmp->index = 0;
		*dest = tmp;
	}
	else
		ft_lstadd_front_int(dest, tmp);
	print_operation("p", (*dest)->name);
	return (ft_lstsize_int(src));
}

void	swap(t_list_int **stack, int prnt)
{
	int			n;

	n = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = n;
	if (prnt)
		print_operation("s", (*stack)->name);
}

void	print_operation(char *operate, char stack_name)
{
	char		dest[5];
	int			i;

	i = 0;
	while (operate[i])
	{
		dest[i] = operate[i];
		i++;
	}
	dest[i++] = stack_name;
	dest[i] = 0;
	printf("%s\n", dest);
}

void	re_index(t_list_int **stack, long *maxInd, long *minInd)
{
	t_operate	s;

	s.tmp = *stack;
	set1(&s);
	s.mean = ft_lstsize_int(stack) / 2;
	while (s.tmp)
	{
		if (s.tmp->val > s.max_val)
		{
			s.max_val = s.tmp->val;
			*maxInd = s.i;
		}
		if (s.tmp->val < s.min_val)
		{
			s.min_val = s.tmp->val;
			*minInd = s.i;
		}
		s.tmp->index = s.i++;
		if (s.tmp->index <= s.mean)
			s.tmp->direction = 0;
		else
			s.tmp->direction = 1;
		s.tmp = s.tmp->next;
	}
}

void	find_tar_node(t_list_int **stackA, t_list_int **stackB, long maxIndex)
{
	t_tmp	s;

	s.tmp_a = *stackA;
	s.tmp_b = *stackB;
	s.i = 0;
	while (s.tmp_a)
	{
		s.tmp_b = *stackB;
		s.tmp_diff = 0;
		s.found = 0;
		s.tmp_a->diff_val = INT_MAX;
		s.tmp_a->index = s.i;
		check_diff_a(&s, maxIndex);
		s.tmp_a = s.tmp_a->next;
		s.i++;
	}
}
