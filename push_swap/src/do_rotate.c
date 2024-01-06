/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:43:17 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/24 19:31:11 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_list_int **stackA, t_list_int **stackB, long index)
{
	int			i;
	t_list_int	*tmp_a;

	i = 0;
	tmp_a = *stackA;
	while (i < index)
	{
		tmp_a = tmp_a->next;
		i++;
	}
	i = 0;
	while (i < tmp_a->target_node)
	{
		rotate(stackA, 1, 0);
		rotate(stackB, 1, 0);
		printf("rr\n");
		i++;
	}
	while (i < index)
	{
		rotate(stackA, 1, 1);
		i++;
	}
}

void	do_rotate2(t_list_int **stackA, t_list_int **stackB, long index)
{
	int			i;
	t_list_int	*tmp_a;

	i = 0;
	tmp_a = *stackA;
	while (i < index)
	{
		tmp_a = tmp_a->next;
		i++;
	}
	i = 0;
	while (i < index)
	{
		rotate(stackA, 1, 0);
		rotate(stackB, 1, 0);
		printf("rr\n");
		i++;
	}
	while (i < tmp_a->target_node)
	{
		rotate(stackB, 1, 1);
		i++;
	}
}

void	dual_rotate(t_list_int **stackA, t_list_int **stackB, long index)
{
	t_list_int	*tmp_a;
	long		i;

	tmp_a = *stackA;
	i = 0;
	while (i < index)
	{
		tmp_a = tmp_a->next;
		i++;
	}
	if (index > tmp_a->target_node)
		do_rotate(stackA, stackB, index);
	else
		do_rotate2(stackA, stackB, index);
}
