/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <niran.analas@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:44:25 by npiyapan          #+#    #+#             */
/*   Updated: 2023/11/10 18:53:14 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_writestr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_check(va_list *args, const char *str)
{
	int	len;

	len = 0;
	// if (str == 'c')
	// 	len += ft_write(va_arg(args, int));
	// else if (str == 's')
	// 	len += ft_writestr(va_arg(*args, char *));
	// else if (str == 'p')
	// 	len += ft_writeptr(va_arg(args, unsigned long long));
	// else if (str == 'd' || str == 'i')
	// 	len += ft_writedec(va_arg(args, int));
	// else if (str == 'u')
	// 	len += ft_writeunsignedi(va_arg(args, unsigned int));
	// else if (str == 'x' || str == 'X')
	// 	len += ft_writehex(va_arg(args, unsigned int), str);
	// else if (str == '%')
	// 	len += write(1, "%", 1);

	if (*str == 's')
		len += ft_writestr(va_arg(*args, char *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check(&args, str + i + 1);
			i++;
		}
		else
			len += ft_write(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

//  int	main(void)
//  {
// 	// char *a = "1234";
// 	// printf("len = %i\n",    printf("test %s %c %p %d %i %u %x %X %%\n", 
//a, 'a', a, -1, -256, -2147483647, 2147483647, 2147483647));
// 	// printf("len = %i\n", ft_printf("test %s %c %p %d %i %u %x %X %%\n", 
//a, 'a', a, -1, -256, -2147483647, 2147483647, 2147483647));
// 	// printf(" NULL %s NULL ", NULL);
// 	//ft_printf(" NULL %s NULL ", NULL);
//  	ft_printf("%s", NULL);
//  }