/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:44:53 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/08 15:00:28 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (n == 0)
		return (src_len);
	while (i < n -1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
		dest[i] = '\0';
	return (src_len);
}
