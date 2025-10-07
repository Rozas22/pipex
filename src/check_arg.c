/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:30:48 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/07 17:42:24 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_str_matr(char **m)
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

t_cmnd_line	*ft_open_fds(int argc, char **argv)
{
	t_cmnd_line	*args;

	(void)argc;
	args = (t_cmnd_line *)malloc(sizeof(t_cmnd_line));
	if (!args)
		return (NULL);
	args->fd_in = open(argv[1], O_RDONLY);
	args->fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	return (args);
}

t_cmnd_line	*ft_arg_check(int argc, char **argv, char **envp)
{
	t_cmnd_line	*args;

	if (argc != 5)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	args = ft_open_fds(argc, argv);
	if (!args)
		return (NULL);
	args->path = ft_get_path(envp);
	args->cmnds = ft_get_cmnds(argc, argv);
	if (!args->cmnds)
	{
		if (args->path)
			free_str_matr(args->path);
		free(args);
		return (NULL);
	}
	return (args);
}
