/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:59:30 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/06 15:25:31 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_child1(int pipefd[2], t_pipex *vars, char *envp[])
{
	catch_syserr(dup2(vars->input_fd, STDIN_FILENO),
		"dup2 input_fd to stdin");
	catch_syserr(dup2(pipefd[1], STDOUT_FILENO),
		"dup2 pipefd[1] to stdout");
	cleanup_fds(pipefd[0], pipefd[1], vars->input_fd, vars->output_fd);
	execute_cmd(vars->cmd1, envp);
	exit_perr("cmd1 execve");
}

static void	execute_child2(int pipefd[2], t_pipex *vars, char *envp[])
{
	catch_syserr(dup2(pipefd[0], STDIN_FILENO),
		"dup2 pipefd[0] to stdin");
	catch_syserr(dup2(vars->output_fd, STDOUT_FILENO),
		"dup2 output_fd to stdout");
	cleanup_fds(pipefd[0], pipefd[1], vars->input_fd, vars->output_fd);
	execute_cmd(vars->cmd2, envp);
	exit_perr("cmd2 execve");
}

// if (WIFEXITED(state->status1))
// 	ft_printf("cmd1 done\n");
// if (WIFEXITED(state->status2))
// 	ft_printf("cmd2 done\n");
// if (WIFEXITED(state->status1) && WIFEXITED(state->status2))
// 	ft_printf("pipe done\n");
static void	execute_parent_final(t_pipex_state *state,
	int pipefd[2], t_pipex *vars)
{
	cleanup_fds(pipefd[0], pipefd[1], vars->input_fd, vars->output_fd);
	waitpid(state->pid1, &state->status1, 0);
	waitpid(state->pid2, &state->status2, 0);
}

void	execute_pipe(t_pipex *vars, char *envp[])
{
	int				pipefd[2];
	t_pipex_state	state;

	catch_syserr(pipe(pipefd), "create pipe");
	state.pid1 = fork();
	if (state.pid1 < 0)
		exit_perr("Fork 1 failed");
	if (state.pid1 == 0)
		execute_child1(pipefd, vars, envp);
	else
	{
		state.pid2 = fork();
		if (state.pid2 < 0)
			exit_perr("Fork 2 failed");
		else if (state.pid2 == 0)
			execute_child2(pipefd, vars, envp);
		else
			execute_parent_final(&state, pipefd, vars);
	}
}
