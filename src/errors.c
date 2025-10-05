/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:30:53 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/05 18:52:18 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_triple_free(void ***ptr);
void	ft_double_free(void **ptr);
void	ft_close_fds(t_cmnd_line *args);
void	ft_write_error(int e_type);

void	*ft_free_struct(t_cmnd_line *args, int e_type)
{
	ft_write_error(e_type);
	if (e_type == 0)
		e_type = 2;
	if (e_type >= 0)
	{
		while (e_type >= 0)
		{
			if (e_type == 0)
				ft_close_fds(args);
			else if (e_type == 1)
				ft_double_free((void **)args->path);
			else if (e_type == 2)
				ft_triple_free((void ***)args->cmnds);
			e_type -= 1;
		}
		return (free(args), NULL);
	}
	else
		return (NULL);
}

void	ft_write_error(int e_type)
{
	if (e_type >= -1 && e_type < 5)
		ft_putstr_fd("Error.\n", 2);
	if (e_type == -1)
		ft_putstr_fd("An error ocurred while opening the fds.\n", 2);
	else if (e_type == 1)
		ft_putstr_fd("An error ocurred while working with PATH.\n", 2);
	else if (e_type == 2)
		ft_putstr_fd("An error ocurred while checking comands.\n", 2);
	else if (e_type == 3)
		ft_putstr_fd("An error ocurred while checking access.\n", 2);
	else if (e_type == 4)
		ft_putstr_fd("An error ocurred while creating a pipe.\n", 2);
}

void	ft_close_fds(t_cmnd_line *args)
{
	close(args->fd_in);
	close(args->fd_out);
}

void	ft_double_free(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_triple_free(void ***ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		ft_double_free(ptr[i]);
		i++;
	}
	free(ptr);
}
