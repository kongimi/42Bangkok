/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:52:41 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/22 12:09:22 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front_int(t_list_int **lst, t_list_int *new)
{
	if (!lst || !new)
		return ;
	(*new).index = 0;
	new->next = *lst;
	*lst = new;
}
