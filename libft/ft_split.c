/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:09:45 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/08 15:32:52 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_stringnum(const char *s, char c)
{
	int	num;
	int	in_str;

	num = 0;
	in_str = 0;
	while (*s != '\0')
	{
		if (*s != c && in_str == 0)
		{
			in_str = 1;
			num++;
		}
		else if (*s == c)
			in_str = 0;
		s++;
	}
	return (num);
}

static char	*ft_strndup(const char *s, int n)
{
	char	*word;
	int		i;

	word = malloc((n + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < n)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(	char **result, int i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;

	result = malloc((ft_stringnum(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			result[i] = ft_strndup(s, len);
			if (!result[i++])
				return (ft_free(result, i));
			s += len;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
