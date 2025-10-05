/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:37:54 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/29 15:52:36 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex_ptr(unsigned long num)
{
	if (num >= 16)
		print_hex_ptr(num / 16);
	write(1, &"0123456789abcdef"[num % 16], 1);
}

int	ft_printptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	addr = (unsigned long)ptr;
	count = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		print_hex_ptr(addr);
	}
	while (addr)
	{
		count++;
		addr /= 16;
	}
	return (count + 2);
}
