/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:30:57 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/05 20:48:20 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	safe_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		exit(1);
}

static void	setup_io_c1(int fd[2], int in)
{
	safe_dup2(in, STDIN_FILENO);
	safe_dup2(fd[1], STDOUT_FILENO);
	close(in);
	close(fd[1]);
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

void	child_process(int fd[2], t_cmnd_line *args, char **envp)
{
	char	*path;

	close(fd[0]);
	if (args->fd_in < 0)
	{
		close(fd[1]);
		ft_cleanup_args(args);
		exit(1);
	}
	setup_io_c1(fd, args->fd_in);
	if (!args->cmnds || !args->cmnds[0] || !args->cmnds[0][0]
		|| args->cmnds[0][0][0] == '\0')
		cmd_not_found(args, NULL);
	path = ft_pathfinder(args->cmnds[0][0], args->path);
	if (!path)
		cmd_not_found(args, args->cmnds[0][0]);
	execve(path, args->cmnds[0], envp);
	perror(path);
	free(path);
	ft_cleanup_args(args);
	exit(126);
}
