/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:47:57 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/10 18:49:50 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_pf
{
	char			*res;
	size_t			len;
	size_t			i;
	long			mm;
	int				nn;
	unsigned int	ui;
}	t_pf;

int		ft_printf(const char *str, ...);
int		ft_write(int c);
int		ft_writestr(char *str);
int		ft_check(va_list *args, const char *str);
int		ft_writeptr(unsigned long long ptr);
int		ft_writedec(int c);
int		ft_writeunsignedi(unsigned int c);
int		ft_writehex(unsigned int c, char str);
size_t	ft_findlen(unsigned long long ptr, int base);
size_t	ft_findlen_ui(unsigned int ptr, int base);
char	*ft_itoa_printf(unsigned long long ptr, int base);
char	*ft_itoa_dec(int ptr, int base);
char	*ft_itoa_ui(unsigned int ptr, int base);
void	ft_base(t_pf *pf, int base);

#endif