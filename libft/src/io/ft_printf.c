/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:31:43 by emorvan           #+#    #+#             */
/*   Updated: 2022/05/02 13:28:37 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	params;

	i = 0;
	len = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_formatter(params, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(params);
	return (len);
}

int	ft_formatter(va_list params, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(params, int));
	else if (format == 's')
		len += ft_putstr(va_arg(params, char *));
	else if (format == 'p')
		len += ft_putptr(va_arg(params, unsigned long long));
	else if (format == 'd')
		len += ft_putnbr(va_arg(params, int));
	else if (format == 'i')
		len += ft_putnbr(va_arg(params, int));
	else if (format == 'u')
		len += ft_putunsigned(va_arg(params, unsigned int));
	else if (format == 'x')
		len += ft_puthex(va_arg(params, unsigned int), format);
	else if (format == 'X')
		len += ft_puthex(va_arg(params, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}
