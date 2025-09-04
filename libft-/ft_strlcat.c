/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:49:13 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/08 15:00:50 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	i = 0;
	d_len = 0;
	s_len = 0;
	while (dest[d_len] != '\0' && d_len < n)
		d_len++;
	while (src[s_len] != '\0')
		s_len++;
	if (n <= d_len)
		return (n + s_len);
	while (i < n - d_len - 1 && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
