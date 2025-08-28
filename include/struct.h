/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:53:37 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/04 04:38:12 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_pipex
{
	int		input_fd; // fd to read from
	int		output_fd; // fd to write to
	char	*cmd1;
	char	*cmd2;
}	t_pipex;

typedef struct s_npipex
{
	int		heredoc_on;
	char	*limiter;

	int		input_fd;
	int		output_fd;
	size_t	cmd_count;
	char	**cmds;
}	t_npipex;

typedef struct s_pipex_state
{
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;
}	t_pipex_state;

typedef struct s_npipex_state
{
	size_t	cmd_idx;
	pid_t	*c_pids;
	pid_t	curr_pid;
	int		prev_fd_in;
}	t_npipex_state;

#endif