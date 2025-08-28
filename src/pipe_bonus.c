/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 03:08:49 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/23 05:41:04 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
	@brief Executes a single child process for a command in the pipeline.
	Redirects input and output and executes the current command. If the
	execution fails, exits with an error message.

	@param state Pointer to pipeline state struct
	@param pipefd Pipe file descriptors (0 - read, 1 - write)
	@param vars Pointer to main npipex variable struct
	@param envp Array of environment variables passed to main
*/
static void	execute_child(t_npipex_state *state,
	int pipefd[2], t_npipex *vars, char *envp[])
{
	catch_syserr(dup2(state->prev_fd_in, STDIN_FILENO),
		"dup2 prev_fd_in to stdin");
	if (state->cmd_idx < (vars->cmd_count - 1))
		catch_syserr(dup2(pipefd[1], STDOUT_FILENO),
			"dup2 pipefd[1] to stdout");
	else
		catch_syserr(dup2(vars->output_fd, STDOUT_FILENO),
			"dup2 output_fd to stdout");
	if (state->prev_fd_in != STDIN_FILENO)
		close(state->prev_fd_in);
	if (state->cmd_idx < (vars->cmd_count - 1))
		close_io(pipefd[0], pipefd[1]);
	execute_cmd(vars->cmds[state->cmd_idx], envp);
	exit_perr("execute cmd failed");
}

/**
	@brief Waits for all child processes in the pipeline to complete,
	then frees the array of child PIDs

	@param c_pids Pointer to array of child PIDs
	@param vars Pointer to t_npipex variable struct
*/
static void	wait_for_children(pid_t **c_pids, t_npipex *vars)
{
	size_t	idx;
	int		status;

	idx = 0;
	while (idx < vars->cmd_count)
	{
		status = 0;
		if ((*c_pids)[idx] > 0)
			waitpid((*c_pids)[idx], &status, 0);
		idx++;
	}
	free(*c_pids);
}

/**
	@brief Updates the pipeline state after forking a child. Closes
	the previous input file descriptor, stores the current PID, and
	updates prev_fd_in if there is still another command remaining
	in the pipeline.

	@param state Pointer to current pipeline state
	@param pipefd Pipe file descriptor (0 - read, 1 - write)
	@param vars Pointer to t_pipex structure
*/
static void	update_pipeline(t_npipex_state *state,
	int pipefd[2], t_npipex *vars)
{
	close(state->prev_fd_in);
	state->c_pids[state->cmd_idx] = state->curr_pid;
	if (state->cmd_idx < (vars->cmd_count - 1))
	{
		close(pipefd[1]);
		state->prev_fd_in = pipefd[0];
	}
}

/**
	@brief Initializes the pipeline execution state. Sets up heredoc input if
	enabled, allocates memory for child PIDs, and sets the current command index

	@param vars Pointer to main t_npipex variable struct
	@param state Pointer to pipeline state struct to initialize
*/
static void	init_state(t_npipex *vars, t_npipex_state *state)
{
	int	heredoc_pipefd[2];

	if (vars->heredoc_on)
	{
		pipe(heredoc_pipefd);
		handle_heredoc(vars, heredoc_pipefd);
		state->prev_fd_in = heredoc_pipefd[0];
	}
	else
		state->prev_fd_in = vars->input_fd;
	state->c_pids = malloc(vars->cmd_count * sizeof(pid_t));
	if (!state->c_pids)
		exit_perr("malloc failed");
	ft_memset(state->c_pids, -1, vars->cmd_count * sizeof(pid_t));
	state->cmd_idx = 0 + vars->heredoc_on;
}

/**
	@brief Executes a series of n piped commands with optional heredoc support.

	@param vars Pointer to initialized t_npipex variable struct
	@param envp Environment variables array passed to main
*/
void	execute_npipe(t_npipex *vars, char *envp[])
{
	int				pipefd[2];
	t_npipex_state	state;

	init_state(vars, &state);
	while (state.cmd_idx < vars->cmd_count)
	{
		if (state.cmd_idx < (vars->cmd_count - 1))
			catch_syserr(pipe(pipefd), "pipe failed");
		state.curr_pid = fork();
		if (state.curr_pid < 0)
			exit_perr("fork failed");
		if (state.curr_pid == 0)
			execute_child(&state, pipefd, vars, envp);
		else
			update_pipeline(&state, pipefd, vars);
		state.cmd_idx++;
	}
	close(state.prev_fd_in);
	close_io(vars->input_fd, vars->output_fd);
	free_npipex(vars);
	wait_for_children(&state.c_pids, vars);
}
