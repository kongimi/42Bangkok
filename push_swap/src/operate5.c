/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:50:03 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/29 14:38:00 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_push_b(t_tmp *s, t_list_int **stackA, t_list_int **stackB)
{
	ft_bzero(s, sizeof(t_list_int));
	s->tmp_a = *stackA;
	s->tmp_b = *stackB;
}

int	check_only_one_sign(char **tmp, t_swap *s)
{
	if (s->i == 0 && s->j == 0)
	{
		if (s->k == '-' || s->k == '+')
			if (!tmp[s->i][s->j + 1])
				return (1);
	}
	return (0);
}
