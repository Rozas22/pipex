/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:33:06 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/05 20:46:11 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_cmnd_line
{
	int		fd_in;
	int		fd_out;
	char	***cmnds;
	char	**path;
}	t_cmnd_line;

t_cmnd_line	*ft_arg_check(int argv, char **argl, char **envp);
void		*ft_free_struct(t_cmnd_line *cmnds, int e_type);
char		*ft_pathfinder(char *aux_c, char **paths);
void		child_process(int fd[2], t_cmnd_line *args, char **envp);
void		parent_process(int fd[2], t_cmnd_line *args, char **envp);
char		***ft_get_cmnds(int argc, char **argv);
char		**ft_get_path(char **envp);
void		ft_cleanup_args(t_cmnd_line *a);

void		print_args(char ***args);
#endif