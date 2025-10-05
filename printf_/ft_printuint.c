/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:00 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/28 16:42:54 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_printuint(n / 10);
	ft_putchar((n % 10) + '0');
	return (count + 1);
}
