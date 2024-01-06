/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:16:16 by npiyapan          #+#    #+#             */
/*   Updated: 2024/01/03 17:27:59 by npiyapan         ###   ########.fr       */
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

	s.i = 0;
	s.sign = 0;
	while (tmp[s.i])
	{
		s.j = 0;
		while (tmp[s.i][s.j])
		{
			s.k = tmp[s.i][s.j];
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

int	do_command(char *line, t_list_int **stack_a, t_list_int **stack_b, int *err)
{
	int	found;

	found = 0;
	if (check_swap(line, stack_a, stack_b) == 1)
		return (1);
	else if (check_swap(line, stack_a, stack_b) == 2)
		return (set_err(err));
	else if (check_ro(line, stack_a, stack_b) == 1)
		return (1);
	else if (check_ro(line, stack_a, stack_b) == 2)
		return (set_err(err));
	else if (check_push(line, stack_a, stack_b) == 1)
		return (1);
	else if (check_push(line, stack_a, stack_b) == 2)
		return (set_err(err));
	else if (check_rev(line, stack_a, stack_b) == 1)
		return (1);
	else if (check_rev(line, stack_a, stack_b) == 2)
		return (set_err(err));
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_tmp		s;
	char		*line;

	ft_bzero(&s, sizeof(t_list_int));
	if (check_error_input(argc, argv, &s.stack_a, &s.fin))
		return (set_error_checker(&s));
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL || line[0] == '\n')
			break ;
		if (!do_command(line, &s.stack_a, &s.stack_b, &s.do_err))
			return (display_err(line));
		if (s.do_err)
			break ;
		free(line);
		if (is_sort(&s.stack_a) && (ft_lstsize_int(&s.stack_b) == 0))
			break ;
	}
	if (is_sort(&s.stack_a) && (ft_lstsize_int(&s.stack_b) == 0) && !s.do_err)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all_list(&s.stack_a, &s.stack_b);
	return (0);
}
