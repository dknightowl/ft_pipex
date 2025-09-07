/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 08:54:17 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/07 16:00:32 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_io(int fd_in, int fd_out)
{
	close(fd_in);
	close(fd_out);
}

void	cleanup_fds(int pipe_fd1, int pipe_fd2, int fd_in, int fd_out)
{
	close_io(pipe_fd1, pipe_fd2);
	close_io(fd_in, fd_out);
}

void	free_npipex(t_npipex *vars)
{
	free(vars->cmds);
	free(vars->limiter);
}
