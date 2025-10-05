/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:45:35 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/05 20:52:59 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	px_free_matrix(char **m)
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

static void	px_free_cmdvv(char ***v)
{
	if (!v)
		return ;
	if (v[0])
		px_free_matrix(v[0]);
	if (v[1])
		px_free_matrix(v[1]);
	free(v);
}

void	ft_cleanup_args(t_cmnd_line *a)
{
	if (!a)
		return ;
	if (a->path)
		px_free_matrix(a->path);
	if (a->cmnds)
		px_free_cmdvv(a->cmnds);
	free(a);
}
