/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:45:35 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/07 17:42:44 by ikrozas          ###   ########.fr       */
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

static void	free_cmdvv(char ***v)
{
	if (!v)
		return ;
	if (v[0])
		free_str_matr(v[0]);
	if (v[1])
		free_str_matr(v[1]);
	free(v);
}

void	ft_cleanup_args(t_cmnd_line *a)
{
	if (!a)
		return ;
	if (a->path)
		free_str_matr(a->path);
	if (a->cmnds)
		free_cmdvv(a->cmnds);
	free(a);
}
