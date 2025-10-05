/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:37:51 by ikrozas           #+#    #+#             */
/*   Updated: 2024/10/08 15:03:44 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getnumlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_strrev(char *str)
{
	int		start;
	int		end;
	char	c;

	start = 0;
	end = 0;
	while (str[end])
		end++;
	end--;
	while (start < end)
	{
		c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
	}
	return (str);
}

int	ft_abs(int c)
{
	if (c < 0)
		c = -c;
	return (c);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	size_t	i;

	nbr = n;
	i = 0;
	str = (char *)malloc(sizeof(char) * (getnumlen(n) + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[i++] = '0';
	if (n < 0)
		str[i++] = '-';
	while (nbr != 0)
	{
		str[i++] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
	}
	str[i] = '\0';
	if (str[0] == '-')
		ft_strrev(str + 1);
	else
		ft_strrev(str);
	return (str);
}
