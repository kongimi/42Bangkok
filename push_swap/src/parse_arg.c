/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:39:04 by npiyapan          #+#    #+#             */
/*   Updated: 2023/12/29 15:03:45 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_newlst(t_list_int **stackA, t_parse *p)
{
	p->new_l->index = p->ind;
	p->new_l->name = 'a';
	p->ind++;
	ft_lstadd_back_int(stackA, p->new_l);
	p->j++;
}

int	free_tmp(t_parse *p)
{
	ft_free_split(p->tmp);
	return (1);
}

int	parse_int(char **argv, t_list_int **stackA)
{
	t_parse	p;

	p.i = 1;
	p.ind = 0;
	while (argv[p.i])
	{
		p.tmp = ft_split(argv[p.i], ' ');
		p.j = 0;
		while (p.tmp[p.j])
		{
			p.error = 0;
			p.ans = ft_atoi_2(p.tmp[p.j], &p.error);
			if (p.ans > INT_MAX || p.ans < INT_MIN || p.error)
				return (free_tmp(&p));
			p.new_l = ft_lstnew_int(p.ans);
			if (!p.new_l)
				return (free_tmp(&p));
			set_newlst(stackA, &p);
		}
		ft_free_split(p.tmp);
		p.i++;
	}
	return (0);
}
