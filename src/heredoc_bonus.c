/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:24:01 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/21 05:50:08 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
	@brief Performs cleanup upon the completion of a heredoc child process.
	Closes input file descriptor, closes the write end of the heredoc pipe, and
	waits for the child process to terminate.

	@param vars Pointer to t_npipex struct containing the input file descriptor
	@param pipefd Pipe file descriptors array (0 - read, 1 - write)
	@param pid Pointer to PID of the child process
	@param status Pointer to an integer where the child's exit status is stored
*/
static void	cleanup(t_npipex *vars, int pipefd[2], pid_t *pid, int *status)
{
	close(vars->input_fd);
	close(pipefd[1]);
	waitpid(*pid, status, 0);
}

/**
	@brief Reads lines from heredoc input and writes it to stdout until
	the limiter string is encountered

	@param vars Pointer to t_npipex struct containing the input file
	descriptor and limiter string
*/
static void	heredoc_loop(t_npipex *vars)
{
	char	*line;
	size_t	limiter_len;

	line = NULL;
	limiter_len = ft_strlen(vars->limiter);
	while (1)
	{
		if (line)
			free(line);
		line = get_next_line(vars->input_fd);
		if (ft_strncmp(line, vars->limiter, limiter_len) == 0
			&& (ft_strlen(line) == limiter_len))
		{
			free(line);
			break ;
		}
		write(STDOUT_FILENO, line, ft_strlen(line));
	}
}

/**
	@brief Handles the heredoc functionality by forking a child to process
	the user's input if heredoc mode is toggled. Within the child, the
	heredoc input is read via heredoc_loop and written to stdout.
	The parent runs the cleanup operation and waits for the child to
	complete

	@param vars Pointer to t_npipex struct
	@param pipefd Pipe file descriptors array (0 - read, 1, write)
*/
void	handle_heredoc(t_npipex *vars, int pipefd[2])
{
	pid_t	pid;
	int		status;

	if (vars->heredoc_on)
	{
		status = 0;
		pid = fork();
		if (pid == 0)
		{
			close(pipefd[0]);
			catch_syserr(dup2(pipefd[1], STDOUT_FILENO),
				"dup2 pipefd[1] to stdout");
			close(pipefd[1]);
			heredoc_loop(vars);
			close_io(vars->input_fd, vars->output_fd);
			close(STDOUT_FILENO);
			exit(0);
		}
		else
			cleanup(vars, pipefd, &pid, &status);
	}
}
