/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:35:06 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/29 15:49:13 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cases(char format, va_list args)
{
	int		countchars;
	char	c;

	countchars = 0;
	if (format == 'c')
	{
		c = (char)va_arg(args, int);
		countchars += write(1, &c, 1);
	}
	else if (format == 's')
		countchars += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		countchars += ft_printptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		countchars += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		countchars += ft_printuint(va_arg(args, unsigned int));
	else if (format == 'x')
		countchars += ft_printhex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		countchars += ft_printhex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		countchars += write(1, "%", 1);
	return (countchars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		countchars;

	va_start(args, format);
	countchars = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			countchars += cases(*format, args);
		}
		else
			countchars += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (countchars);
}
