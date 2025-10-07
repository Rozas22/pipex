/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:55:10 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/07 17:59:51 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_str_matr(char **m)
{
	size_t	i;

	if (!m)
		return ;
	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}

static void	free_cmdv_until(char ***cmnds, int upto)
{
	while (--upto >= 0)
		if (cmnds[upto])
			free_str_matr(cmnds[upto]);
}

static char	**parse_cmd_token(const char *s)
{
	if (!s || s[0] == '\0')
		return (NULL);
	return (ft_split(s, ' '));
}

static int	fill_cmds(char ***cmnds, int cnt, char **argv)
{
	int	i;

	i = 0;
	while (i < cnt - 1)
	{
		cmnds[i] = parse_cmd_token(argv[i + 2]);
		if (argv[i + 2] && argv[i + 2][0] && !cmnds[i])
		{
			free_cmdv_until(cmnds, i);
			return (1);
		}
		i++;
	}
	cmnds[cnt - 1] = NULL;
	return (0);
}

char	***ft_get_cmnds(int argc, char **argv)
{
	char	***cmnds;
	int		cnt;

	cnt = argc - 2;
	cmnds = (char ***)malloc(sizeof(char **) * cnt);
	if (!cmnds)
		return (NULL);
	if (fill_cmds(cmnds, cnt, argv))
	{
		free(cmnds);
		return (NULL);
	}
	return (cmnds);
}
