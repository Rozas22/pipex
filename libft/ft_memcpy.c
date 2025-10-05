/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:54:05 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/08 14:29:53 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}
