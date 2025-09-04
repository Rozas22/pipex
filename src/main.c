/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:23:48 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/03 16:34:22 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void cleanup_parent(int pipefd[2], int infile, int	outfile,
						pid_t p1, pid_t p2)
{
close(pipefd[0]);
close(pipefd[1]);
close(infile);
close(outfile);
waitpid(p1, NULL, 0):
waitpid(p2, NULL, 0);						
}

static void	run_pipex(char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_exit("Error al abrir infile");
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit("Error al abrir outfile");
	if (pipe(pipefd) == -1)
		error_exit("Error al crear pipe");
	pid1 = fork();
	if (pid1 == -1)
		error_exit("fork");
	if (pid1 == 0)
		primera_parte(infile, pipefd, argv[2], envp);
	pid2 = fork();
	if (pid2 == -1)
		error_exit("fork");
	if (pid2 == 0)
		segunda_parte(outfile, pipefd, argv[3], envp);
	cleanup_parent(pipefd, infile, outfile, pid1, pid2);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putendl_fd("Uso: ./pipex archivo1 cmd1 cmd2 archivo2", 2);
		return (1);
	}
	run_pipex(argv, envp);
	return (0);
}
