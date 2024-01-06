/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:10:24 by npiyapan          #+#    #+#             */
/*   Updated: 2024/01/03 15:33:09 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sign(int k, int sign)
{
	if (k == '-' || k == '+')
	{
		if (sign)
			return (1);
	}
	return (0);
}

int	check_digit(char **tmp)
{
	t_swap	s;

	ft_bzero(&s, sizeof(t_swap));
	while (tmp[s.i])
	{
		s.j = 0;
		while (tmp[s.i][s.j])
		{
			s.k = tmp[s.i][s.j];
			if (check_only_one_sign(tmp, &s))
				return (1);
			if ((s.k >= '0' && s.k <= '9') || s.k == '-' || s.k == '+')
			{
				if (check_sign(s.k, s.sign))
					return (1);
				s.sign = 1;
			}
			else
				return (1);
			s.j++;
		}
		s.sign = 0;
		s.i++;
	}
	return (0);
}

int	check_error_input(int argc, char **argv, t_list_int **stackA, int *fin)
{
	if (argc == 1)
		return (0);
	if (check_digit_all(argc, argv))
		return (1);
	if (parse_int(argv, stackA))
		return (1);
	if (is_sort(stackA) == 1)
		*fin = 1;
	else if (is_sort(stackA) == 2)
		return (1);
	if (check_dup(stackA))
		return (1);
	return (0);
}

void	sort_data(t_list_int **stack_a, t_list_int **stack_b, t_tmp *s)
{
	if (s->size > 3 && !is_sort(stack_a))
		s->size = push(stack_a, stack_b);
	if (s->size > 3 && !is_sort(stack_a))
		s->size = push(stack_a, stack_b);
	while (s->size > 3 && !is_sort(stack_a))
		s->size = push_to_b(stack_a, stack_b, &s->max_ind_b);
	if (s->size == 3)
		sort_three(stack_a);
	re_index(stack_a, &s->max_ind_a, &s->min_ind_a);
	s->size = ft_lstsize_int(stack_b);
	while (s->size)
	{
		re_index(stack_b, &s->max_ind_b, &s->min_ind_b);
		s->size = push_to_a(stack_a, stack_b, &s->min_ind_a);
	}
	re_index(stack_a, &s->max_ind_a, &s->min_ind_a);
	while (!is_sort(stack_a))
	{
		find_min_index(stack_a, &s->min_index);
		target_to_top(stack_a, s->min_index, 1);
	}
}

int	main(int argc, char **argv)
{
	t_tmp		s;

	ft_bzero(&s, sizeof(t_list_int));
	if (check_error_input(argc, argv, &s.stack_a, &s.fin))
	{
		free_list(s.stack_a);
		free_list(s.stack_b);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	s.size = ft_lstsize_int(&s.stack_a);
	if (s.size == 2)
	{
		if (s.stack_a->val > s.stack_a->next->val)
			swap(&s.stack_a, 1);
	}
	else if (s.size == 3)
		sort_three(&s.stack_a);
	else if (s.size > 3)
		sort_data(&s.stack_a, &s.stack_b, &s);
	free_all_list(&s.stack_a, &s.stack_b);
	return (0);
}
