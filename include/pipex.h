/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:22:21 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/09 14:31:06 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "libft-/libft.h"

typedef struct s_cmddata
{
	int		fd_in;
	int		fd_out;
	char	*cmd;
	char	**envp;
}	t_cmddata;

void	perror_exit(const char *msg, int code);
void	free_split(char **arr);
void	cmd_not_found(const char *cmd);

char	*get_env(char **envp, const char *name);
char	*join_path(const char *dir, const char *cmd);
char	*find_cmd_path(char *cmd, char **envp);

void	exec_cmd(char *cmdstr, char **envp);

void	fork_1(int in_fd, int pipe_w, char *cmd1, char *envp);
void	fork_2(int out_fd, int pipe_r, char *cmd2, char *envp);

int		wait_and_status(pid_t pid);

#endif