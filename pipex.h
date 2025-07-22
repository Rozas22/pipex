/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:22:21 by ikrozas           #+#    #+#             */
/*   Updated: 2025/07/22 21:16:44 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "libft/libft.h"

void	error_exit(char *msg);
void	primera_parte(int infile, int *pipefd, char *cmd, char **envp);
void	segunda_parte(int outfile, int *pipefd, char *cmd, char **envp);
void	ejecutar_cmd(char *cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);

#endif