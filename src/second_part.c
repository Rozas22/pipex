/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:02:24 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/09 14:04:20 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	safe_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		perror_exit("dup2", 1);
}

void	fork2(pid_t *pid, t_cmddata *d)
{
	*pid = fork();
	if (*pid == -1)
		perror_exit("fork", 1);
	if (*pid == 0)
	{
		if (d->fd_in == -1)
			perror_exit("outfile", 1);
		safe_dup2(d->fd_in, STDIN_FILENO);
		safe_dup2(d->fd_out, STDOUT_FILENO);
		close(d->fd_in);
		close(d->fd_out);
		exec_cmd(d->cmd, d->envp);
	}
}