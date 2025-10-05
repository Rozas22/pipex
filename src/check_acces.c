/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:53:02 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/05 18:53:03 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_pathfinder(char *aux_c, char **paths);

char	*ft_pathfinder(char *aux_c, char **paths)
{
	char	*full_path;
	int		err;
	int		j;

	err = -1;
	j = -1;
	if (access(aux_c, F_OK) == 0)
		return (aux_c);
	while (paths[++j] && err != 0)
	{
		full_path = ft_strjoin(paths[j], aux_c);
		err = access(full_path, F_OK);
		if (err != 0)
			free(full_path);
	}
	if (err == -1)
		return (NULL);
	else
		return (full_path);
}
