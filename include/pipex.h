/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:26:33 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/20 16:07:56 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define SYSERR_CODE -1

// libft
# include "extra.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "libft.h"

// c libs
# include <fcntl.h> // open
# include <stdlib.h> // malloc, free, exit
/*
	read, write, close, access, dup, dup2, execve,
	fork, pipe, unlink
*/
# include <unistd.h>
# include <stdio.h> // perror
# include <string.h> // strerror
# include <errno.h> // global errno variable
# include <sys/wait.h> // wait, waitpid

// pipex
# include "log.h"
# include "error_msg.h"
# include "struct.h"

// shared
void	catch_syserr(int process_status, char *err_msg);
void	exit_perr(char *err_msg);
void	exit_strerr(int err_code);
void	exit_custom(char *err_msg);
char	*get_cmdpath(char *cmd, char *envp[]);
char	**extract_path_envs(char *envp[]);
void	execute_cmd(char *cmd, char **envp);
void	parse_pipex(char *argv[], t_pipex *pipex);
void	parse_npipex(int argc, char *argv[], t_npipex *npipex);
void	close_io(int fd_in, int fd_out);
void	cleanup_fds(int pipe_fd1, int pipe_fd2, int fd_in, int fd_out);
void	free_npipex(t_npipex *vars);

// mandatory
void	execute_pipe(t_pipex *vars, char *envp[]);
// bonus
void	execute_npipe(t_npipex *vars, char *envp[]);
void	handle_heredoc(t_npipex *vars, int pipefd[2]);

#endif