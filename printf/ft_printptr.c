/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:05:17 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/10 18:29:10 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_findlen(unsigned long long ptr, int base)
{
	size_t				len;
	unsigned long long	my_base;

	len = 1;
	if (ptr < 0)
	{
		ptr = ptr * (-1);
		len++;
	}
	my_base = base - 1;
	while (ptr > my_base)
	{
		len++;
		ptr = ptr / base;
	}
	return (len);
}

void	ft_base(t_pf *pf, int base)
{
	if (base == 16)
	{
		if ((pf->mm % base) > 9)
			pf->res[pf->len - pf->i - 1] = (pf->mm % base) + 'a' - 10;
		else
			pf->res[pf->len - pf->i - 1] = (pf->mm % base) + '0';
	}
	else if (base == 10)
	{
		pf->res[pf->len - pf->i - 1] = (pf->nn % base) + '0';
	}
}

char	*ft_itoa_printf(unsigned long long ptr, int base)
{
	t_pf	pf;

	pf.mm = ptr;
	pf.len = ft_findlen(pf.mm, base);
	pf.res = malloc(sizeof(char) * (pf.len + 1));
	if (pf.res == NULL)
		return (NULL);
	if (pf.mm < 0)
		pf.mm = pf.mm * (-1);
	pf.i = 0;
	while (pf.i < pf.len)
	{
		ft_base(&pf, base);
		pf.mm = pf.mm / base;
		pf.i++;
	}
	pf.res[pf.i] = 0;
	if (ptr < 0)
		pf.res[0] = '-';
	return (pf.res);
}

int	ft_writeptr(unsigned long long ptr)
{
	int		len;
	char	*my_ptr;

	len = 0;
	if (ptr == 0)
	{
		my_ptr = "(null)";
		return (6);
	}
	len += write(1, "0x", 2);
	my_ptr = ft_itoa_printf(ptr, 16);
	len += ft_writestr(my_ptr);
	free (my_ptr);
	return (len);
}
