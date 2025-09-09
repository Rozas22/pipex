/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:23:48 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/09 15:26:19 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_cmds(t_cmddata *d1, t_cmddata *d2,
	char **argv, char **envp, int *fds, int *pipefd)
{
	d1->fd_in = fds[0];
	d1->fd_out = pipefd[1];
	d1->cmd = argv[2];
	d1->envp = envp;
	d2->fd_in = pipefd[0];
	d2->fd_out = fds[1];
	d2->cmd = argv[3];
	d2->envp = envp;
}

static void	close_parent(int *pipefd, int *fds)
{
	close(pipefd[0]);
	close(pipefd[1]);
	if (fds[0] != -1)
		close(fds[0]);
	if (fds[1] != -1)
		close(fds[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int			pipefd[2];
	int			fds[2];
	pid_t		pids[2];
	t_cmddata	d1;
	t_cmddata	d2;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
		return (1);
	}
	fds[0] = open(argv[1], O_RDONLY);
	fds[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipe(pipefd) == -1)
		ppx_perror_exit("pipe", 1);
	init_cmds(&d1, &d2, argv, envp, fds, pipefd);
	fork1(&pids[0], &d1);
	fork2(&pids[1], &d2);
	close_parent(pipefd, fds);
	waitpid(pids[0], NULL, 0);
	return (ppx_wait_and_status(pids[1]));
}

/*#include "pipex.h"

static int	open_infile(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

static int	open_outfile(const char *path)
{
	int	fd;

	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	return (fd);
}

static void	make_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		perror_exit("pipe", 1);
}

int	main(int argc, char **argv, char **envp)
{
	int			pipefd[2];
	int			fds[2];
	pid_t		pids[2];
	t_cmddata	d1;
	t_cmddata	d2;

	if (argc != 5)
	{
		ft_putstr_fd("Uso: ./pipex archivo1 cmd1 cmd2 archivo2", 2);
		return (1);
	}
	fds[0] = open_infile(argv[1]);
	fds[1] = open_outfile(argv[4]);
	if (pipe(pipefd) == -1)
		perror_exit("pipe", 1);
	d1.fd_in = fds[0]; d1.fd_out = pipefd[1]; d1.cmd = argv[2]; d1.envp = envp;
	fork2(&pids[1], &d2);
	close(pipefd[0]);
	close(pipefd[1]);
	if (fds[0] != -1)
		close(fds[0]);
	if (fds[1] != -1)
		close(fds[1]);
	waitpid(pids[0], NULL, 0);
	return (wait_and_status(pids[1]));
}*/
