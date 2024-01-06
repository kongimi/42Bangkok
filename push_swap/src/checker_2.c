/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:20:42 by npiyapan          #+#    #+#             */
/*   Updated: 2024/01/03 17:10:39 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_rev(t_tmp *s, t_list_int **stack)
{
	s->found = 1;
	s->size = ft_lstsize_int(stack);
	if (s->size > 1)
		reverse_rotate(stack, 1, 0);
	else
		s->found = 2;
}

int	check_rev(char *line, t_list_int **stack_a, t_list_int **stack_b)
{
	t_tmp	s;

	ft_bzero(&s, sizeof(t_tmp));
	if (ft_strlen(line) == 4 && line[3] == '\n')
	{
		if (!ft_strncmp(line, "rra", 3))
			checker_rev(&s, stack_a);
		else if (!ft_strncmp(line, "rrb", 3))
			checker_rev(&s, stack_b);
		else if (!ft_strncmp(line, "rrr", 3))
		{
			s.found = 1;
			s.size_a = ft_lstsize_int(stack_a);
			s.size_b = ft_lstsize_int(stack_b);
			if (s.size_a > 1 && s.size_b > 1)
			{
				reverse_rotate(stack_a, 1, 0);
				reverse_rotate(stack_b, 1, 0);
			}
			else
				return (2);
		}
	}
	return (s.found);
}

int	set_error_checker(t_tmp *s)
{
	free_list(s->stack_a);
	free_list(s->stack_b);
	ft_putendl_fd("Error", 2);
	return (1);
}

int	display_err(char *line)
{
	ft_putendl_fd("Error", 2);
	free(line);
	return (1);
}

int	set_err(int *err)
{
	*err = 1;
	return (1);
}
