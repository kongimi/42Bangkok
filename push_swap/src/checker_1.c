/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:51:13 by npiyapan          #+#    #+#             */
/*   Updated: 2024/01/03 17:28:15 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_swap(t_tmp *s, t_list_int **stack)
{
	s->found = 1;
	s->size = ft_lstsize_int(stack);
	if (s->size > 1)
		swap(stack, 0);
	else
		s->found = 2;
}

int	check_swap(char *line, t_list_int **stack_a, t_list_int **stack_b)
{
	t_tmp	s;

	ft_bzero(&s, sizeof(t_tmp));
	if (ft_strlen(line) == 3 && line[2] == '\n')
	{
		if (!ft_strncmp(line, "sa", 2))
			checker_swap(&s, stack_a);
		else if (!ft_strncmp(line, "sb", 2))
			checker_swap(&s, stack_b);
		else if (!ft_strncmp(line, "ss", 2))
		{
			s.found = 1;
			s.size_a = ft_lstsize_int(stack_a);
			s.size_b = ft_lstsize_int(stack_b);
			if (s.size_a > 1 && s.size_b > 1)
			{
				swap(stack_a, 0);
				swap(stack_b, 0);
			}
			else
				return (2);
		}
	}
	return (s.found);
}

int	check_ro(char *line, t_list_int **stack_a, t_list_int **stack_b)
{
	t_tmp	s;

	ft_bzero(&s, sizeof(t_tmp));
	if (ft_strlen(line) == 3 && line[2] == '\n')
	{
		if (!ft_strncmp(line, "ra", 2))
			checker_rotate(&s, stack_a);
		else if (!ft_strncmp(line, "rb", 2))
			checker_rotate(&s, stack_b);
		else if (!ft_strncmp(line, "rr", 2))
		{
			s.found = 1;
			rotate(stack_a, 1, 0);
			rotate(stack_b, 1, 0);
		}
	}
	return (s.found);
}

int	push_1(t_list_int **src, t_list_int **dest, int prnt)
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
	if (prnt)
		print_operation("p", (*dest)->name);
	return (ft_lstsize_int(src));
}

int	check_push(char *line, t_list_int **stack_a, t_list_int **stack_b)
{
	int	found;

	found = 0;
	if (ft_strlen(line) == 3 && line[2] == '\n')
	{
		if (!ft_strncmp(line, "pa", 2))
		{
			found = 1;
			if (ft_lstsize_int(stack_b) > 0)
				push_1(stack_b, stack_a, 0);
			else
				found = 2;
		}
		else if (!ft_strncmp(line, "pb", 2))
		{
			found = 1;
			if (ft_lstsize_int(stack_a) > 0)
				push_1(stack_a, stack_b, 0);
			else
				found = 2;
		}
	}
	return (found);
}
