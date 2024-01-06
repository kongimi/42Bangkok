/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:15:51 by npiyapan          #+#    #+#             */
/*   Updated: 2024/01/03 17:17:12 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_rotate(t_tmp *s, t_list_int **stack)
{
	s->found = 1;
	s->size = ft_lstsize_int(stack);
	if (s->size > 1)
		rotate(stack, 1, 0);
	else
		s->found = 2;
}
