/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:28:01 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/08 13:00:39 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	if (s1)
		ft_strlcpy(result, s1, (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s2)
		ft_strlcat(result, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (result);
}
