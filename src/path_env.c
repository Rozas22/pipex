/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:55:48 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/07 17:42:57 by ikrozas          ###   ########.fr       */
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

static char	*find_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static int	append_slash_all(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			return (1);
		free(path[i]);
		path[i] = tmp;
		i++;
	}
	return (0);
}

char	**ft_get_path(char **envp)
{
	char	**path;
	char	*env;

	env = find_env_path(envp);
	if (!env)
		return (NULL);
	path = ft_split(env, ':');
	if (!path)
		return (NULL);
	if (append_slash_all(path))
		return (free_str_matr(path), NULL);
	return (path);
}
