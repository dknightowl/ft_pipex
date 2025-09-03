/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 05:43:21 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/03 20:46:43 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Locate, verify, and execute executables

/**
	@brief Concatenates given environment path and command to
	form a full command path

	@param env Path to environment directory
	@param cmd Command to append

	@return Newly-allocated command path, or NULL upon failure
*/
static char	*make_cmd_path(char *env, char *cmd)
{
	char	*prefix;
	char	*cmdpath;

	prefix = ft_strjoin(env, "/");
	if (!prefix)
		return (NULL);
	cmdpath = ft_strjoin(prefix, cmd);
	free(prefix);
	return (cmdpath);
}

/**
	@brief Frees a partially allocated array of environment paths

	@param envs Pointer to environment paths array
	@param end_idx Index up to which memory should be freed (Inclusive)
*/
static void	free_envs(char ***envs, int end_idx)
{
	while (end_idx)
	{
		free((*envs)[end_idx]);
		end_idx--;
	}
	free(*envs);
}

/**
	@brief Searches directories in PATH to locate full executable path
	of a command. Path must be accessible from the program (i.e. program
	has permissions to the directory) in order for the path string to be
	returned. Else, NULL would be returned if access fails.

	@param cmd Name of command to locate path for
	@param envp Array of environment variables passed to main which
	includes PATH string

	@return Full path to command executable, or NULL if not found
*/
char	*get_cmdpath(char *cmd, char *envp[])
{
	char	**envs;
	char	*path;
	int		idx;

	envs = extract_path_envs(envp);
	path = NULL;
	idx = 0;
	while (envs[idx])
	{
		if (path)
			free(path);
		path = make_cmd_path(envs[idx], cmd);
		if (!path)
			exit_perr("Failed to make cmd path");
		if (access(path, X_OK) == 0)
		{
			free_envs(&envs, idx);
			return (path);
		}
		idx++;
	}
	ft_free2d((void **) envs);
	free(path);
	return (NULL);
}

// cmdargv = ft_split(cmd, ' ');
/**
	@brief Executes given cmd using execve. Parses command into tokens,
	locates the path to its executable on the system, and executes it.

	@param cmd Command string (including its arguments) to be executed
	@param envp Array of environment variables passed to main which
	includes PATH string
*/
void	execute_cmd(char *cmd, char **envp)
{
	char	*cmdpath;
	char	**cmdargv;

	cmdargv = tokenize_cmd(cmd);
	if (!cmdargv)
		exit_custom("Failed to split command vector");
	cmdpath = get_cmdpath(cmdargv[0], envp);
	if (!cmdpath)
	{
		ft_free2d((void **) cmdargv);
		exit_perr("Failed to obtain command path");
	}
	execve(cmdpath, cmdargv, envp);
}
