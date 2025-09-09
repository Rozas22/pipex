/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:04:46 by ikrozas           #+#    #+#             */
/*   Updated: 2025/09/09 14:14:15 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmdstr, char **envp)
{
	char	**argvv;
	char	*path;

	argvv = ft_split(cmdstr, ' ');
	if (!argvv || !argvv[0])
	{
		ft_putstr_fd("pipex: command not found\n", 2);
		free_split(argvv);
		exit(127);
	}
	path = find_cmd_path(argvv[0], envp);
	if (!path)
	{
		cmd_not_found(argvv[0]);
		free_split(argvv);
		exit(127);
	}
	if (execve(path, argvv, envp) == -1)
	{
		perror("execve");
		if (path != argvv[0])
			free(path);
		free_split(argvv);
		exit(126);
	}
}
