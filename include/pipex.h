/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:26:33 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/06 17:04:37 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define SYSERR_CODE -1
# define MAX_ARGS 128
# define MAX_ARG_LEN 1024

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

char	*parse_quoted_token(char *s, int *idx, char q_char);
char	*parse_unquoted_token(char *s, int *idx);
char	**tokenize_cmd(char *cmd);
int		append_char(char *token, int *append_idx, char append_c);
int		advance_on_backslash(char *s, int *idx);
int		append_subquote(char *token, int *t_idx, char *s, int *s_idx);
int		advance_to_next_token(char *cmd, int *s_idx, int t_idx);
char	*parse_token(char *cmd, int *idx);

// mandatory
void	execute_pipe(t_pipex *vars, char *envp[]);
// bonus
void	execute_npipe(t_npipex *vars, char *envp[]);
void	handle_heredoc(t_npipex *vars, int pipefd[2]);

#endif