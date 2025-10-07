/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:31:05 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/07 18:24:04 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	safe_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		exit(1);
}

static void	setup_io_c2(int fd[2], int out)
{
	safe_dup2(fd[0], STDIN_FILENO);
	safe_dup2(out, STDOUT_FILENO);
	close(fd[0]);
	close(out);
}

static void	cmd_not_found(t_cmnd_line *a, const char *name)
{
	if (name && *name)
	{
		write(2, name, ft_strlen(name));
		write(2, ": command not found\n", 20);
	}
	ft_cleanup_args(a);
	exit(127);
}

void	child2_process(int fd[2], t_cmnd_line *args, char **envp)
{
	char	*path;

	close(fd[1]);
	if (args->fd_out < 0)
	{
		close(fd[0]);
		ft_cleanup_args(args);
		exit(1);
	}
	setup_io_c2(fd, args->fd_out);
	if (!args->cmnds || !args->cmnds[1] || !args->cmnds[1][0]
		|| args->cmnds[1][0][0] == '\0')
		cmd_not_found(args, NULL);
	path = ft_pathfinder(args->cmnds[1][0], args->path);
	if (!path)
		cmd_not_found(args, args->cmnds[1][0]);
	execve(path, args->cmnds[1], envp);
	perror(path);
	free(path);
	ft_cleanup_args(args);
	exit(126);
}
