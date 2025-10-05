/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:41:44 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/28 16:42:34 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int num, int uppercase)
{
	int		count;
	char	*hexchar;

	count = 0;
	if (uppercase)
		hexchar = "0123456789ABCDEF";
	else
		hexchar = "0123456789abcdef";
	if (num >= 16)
		count += ft_printhex(num / 16, uppercase);
	ft_putchar(hexchar[num % 16]);
	return (count + 1);
}
