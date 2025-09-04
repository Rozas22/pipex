/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:45:57 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/08 15:00:11 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot__size;
	void	*ptr;

	tot__size = nmemb * size;
	ptr = malloc(tot__size);
	if (ptr != NULL)
		ft_bzero(ptr, tot__size);
	else
		return (NULL);
	return (ptr);
}
