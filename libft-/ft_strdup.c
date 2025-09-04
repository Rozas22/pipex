/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:45:35 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/02 15:46:45 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*cop;

	len = ft_strlen((char *)s) + 1;
	cop = (char *)malloc(len);
	if (cop == NULL)
		return (NULL);
	ft_strlcpy(cop, s, len);
	return (cop);
}
