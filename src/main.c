/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:31:01 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/07 18:24:04 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_pipe_or_perror(int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}

static int	spawn_children(int fd[2], t_cmnd_line *a, char **envp, pid_t p[2])
{
	p[0] = fork();
	if (p[0] == -1)
	{
		perror("fork");
		return (1);
	}
	if (p[0] == 0)
		child_process(fd, a, envp);
	p[1] = fork();
	if (p[1] == -1)
	{
		perror("fork");
		close(fd[0]);
		close(fd[1]);
		waitpid(p[0], NULL, 0);
		return (1);
	}
	if (p[1] == 0)
		child2_process(fd, a, envp);
	return (0);
}

static void	close_parent_fds(t_cmnd_line *a, int fd[2])
{
	close(fd[0]);
	close(fd[1]);
	if (a->fd_in >= 0)
		close(a->fd_in);
	if (a->fd_out >= 0)
		close(a->fd_out);
}

static int	wait_and_exit(pid_t p2, t_cmnd_line *a, pid_t p1)
{
	int	st2;

	waitpid(p1, NULL, 0);
	waitpid(p2, &st2, 0);
	ft_cleanup_args(a);
	if (WIFEXITED(st2))
		return (WEXITSTATUS(st2));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmnd_line	*args;
	int			fd[2];
	pid_t		p[2];

	if (!envp)
		return (1);
	args = ft_arg_check(argc, argv, envp);
	if (!args)
		return (1);
	if (open_pipe_or_perror(fd))
	{
		ft_cleanup_args(args);
		return (1);
	}
	if (spawn_children(fd, args, envp, p))
	{
		ft_cleanup_args(args);
		return (1);
	}
	close_parent_fds(args, fd);
	return (wait_and_exit(p[1], args, p[0]));
}
