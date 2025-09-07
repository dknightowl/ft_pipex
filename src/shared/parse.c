/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:14:16 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/07 15:15:32 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
	@brief Extracts and splits the PATH environment variable into individual
	path string.

	@param envp Array of environment variables passed to main

	@return NULL-terminated array of directory strings, or NULL if PATH is
	not found
*/
char	**extract_path_envs(char *envp[])
{
	char	*env;
	char	*envp_path;
	char	**paths;

	envp_path = NULL;
	while (*envp)
	{
		env = *envp;
		if (ft_strncmp(env, "PATH", 4) == 0)
		{
			envp_path = ft_substr(env, 5, ft_strlen(env) - 4);
			if (!envp_path)
				exit_perr("Failed to parse PATH string");
			paths = ft_split(envp_path, ':');
			free(envp_path);
			if (!paths)
				exit_perr("Failed to split PATH string");
			return (paths);
		}
		envp++;
	}
	return (NULL);
}

/**
	@brief Parses and initializes file descriptors and two commands for pipe

	@param argv Argumument vector (format: infile cmd1 cmd2 outfile)
	@param pipex Pointer to t_pipex struct
*/
void	parse_pipex(char *argv[], t_pipex *pipex)
{
	int	fd_in;
	int	fd_out;

	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_in < 0 || fd_out < 0)
		exit_strerr(errno);
	ft_bzero(pipex, sizeof(pipex));
	pipex->input_fd = fd_in;
	pipex->output_fd = fd_out;
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
}

/**
	@brief Parses and sets file descriptors for npipex. Handles here_doc usage by
	setting fd_in to stdin if here_doc is enabled.

	@param argc Argument count from main
	@param argv Argument vector from main
	@param npipex Pointer to t_npipex struct to update
*/
static void	parse_npipex_fds(int argc, char *argv[], t_npipex *npipex)
{
	int		fd_in;
	int		fd_out;

	if (npipex->heredoc_on)
		fd_in = STDIN_FILENO;
	else
		fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_in < 0 || fd_out < 0)
		exit_strerr(errno);
	npipex->input_fd = fd_in;
	npipex->output_fd = fd_out;
}

/**
	@brief Parses cmd-line arguments and initializes t_npipex structure - which
	handles heredoc detection, sets read/write files, and stores the list of
	commands

	@param argc Argument count from main
	@param argv Argument vector from main
	@param npipex Pointer to t_npipex struct
*/
void	parse_npipex(int argc, char *argv[], t_npipex *npipex)
{
	size_t	cmd_idx;

	ft_bzero(npipex, sizeof(npipex));
	npipex->heredoc_on = ft_strncmp(argv[1], "here_doc", 8) == 0;
	if (npipex->heredoc_on)
		npipex->limiter = ft_strjoin(argv[2], "\n");
	else
		npipex->limiter = NULL;
	parse_npipex_fds(argc, argv, npipex);
	npipex->cmd_count = argc - 3 - npipex->heredoc_on;
	npipex->cmds = (char **) malloc((npipex->cmd_count + 1) * sizeof(char *));
	if (!npipex->cmds)
		exit_perr("malloc failed for npipex->cmds");
	cmd_idx = 0;
	while (cmd_idx < npipex->cmd_count)
	{
		npipex->cmds[cmd_idx] = argv[cmd_idx + 2 + npipex->heredoc_on];
		cmd_idx++;
	}
	npipex->cmds[npipex->cmd_count] = NULL;
}
