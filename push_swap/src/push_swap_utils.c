/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:48:28 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/29 15:16:57 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit_all(int argc, char **argv)
{
	t_swap	s;

	if (argc < 2)
		return (1);
	s.i = 1;
	s.k = 0;
	while (argv[s.i])
	{
		s.k = 0;
		s.tmp = ft_split(argv[s.i], ' ');
		if (!s.tmp)
			return (1);
		if (check_digit(s.tmp))
		{
			ft_free_split(s.tmp);
			return (1);
		}
		ft_free_split(s.tmp);
		s.i++;
	}
	return (0);
}

int	is_sort(t_list_int **stackA)
{
	t_list_int	*tmp;

	tmp = *stackA;
	while (tmp && tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		else if (tmp->val == tmp->next->val)
			return (2);
		tmp = tmp->next;
	}
	return (1);
}

int	check_dup(t_list_int **stackA)
{
	t_list_int	*tmp_next;
	t_list_int	*tmp;

	tmp = *stackA;
	tmp_next = tmp->next;
	while (tmp && tmp->next)
	{
		while (tmp_next)
		{
			if (tmp->val == tmp_next->val)
				return (1);
			tmp_next = tmp_next->next;
		}
		tmp = tmp->next;
		if (tmp->next)
			tmp_next = tmp->next;
	}
	return (0);
}

int	set_error(int *err)
{
	*err = 1;
	return (0);
}

int	ft_atoi_2(const char *str, int *error)
{
	t_swap	s;

	s.i = 0;
	s.res = 0;
	s.mul = 1;
	*error = 0;
	while ((str[s.i] >= 9 && str[s.i] <= 13) || str[s.i] == ' ')
		s.i++;
	if (str[s.i] == '-')
		s.mul = -1;
	if ((s.mul == -1) || (str[s.i] == '+'))
		s.i++;
	while (str[s.i] >= '0' && str[s.i] <= '9')
	{
		s.res = (s.res * 10) + (str[s.i] - '0');
		if (s.mul == -1)
		{
			if (s.res - 1 > INT_MAX)
				return (set_error(error));
		}
		else if (s.res > INT_MAX)
			return (set_error(error));
		s.i++;
	}
	return (s.res * s.mul);
}

// void	print_stack(t_list_int **stack)
// {
// 	t_list_int *tmp;

// 	tmp = *stack;
// 	while (tmp)
// 	{
// 		printf("(%ld) = %d\n", tmp->index, tmp->val);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// }