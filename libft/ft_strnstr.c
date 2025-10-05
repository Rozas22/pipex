/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:18:23 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/02 15:43:00 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	x;
	size_t	llen;

	llen = ft_strlen((char *)little);
	if (llen == 0)
		return ((char *)big);
	if (big == NULL || n < llen)
		return (NULL);
	i = 0;
	while (i <= n - llen)
	{
		x = 0;
		while (x < llen)
		{
			if (big[i + x] != little[x])
				break ;
			x++;
		}
		if (x == llen)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
