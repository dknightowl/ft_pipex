/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 05:50:07 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/14 13:01:42 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	Logging functions
*/

void	putstr(const char *str)
{
	int	len;

	if (!str)
		return ;
	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

void	print_pipex(const t_pipex *p)
{
	if (!p)
	{
		ft_printf("t_pipex is NULL.\n");
		return ;
	}
	ft_printf("=== t_pipex Contents ===\n");
	ft_printf("input_fd:  %d\n", p->input_fd);
	ft_printf("output_fd: %d\n", p->output_fd);
	if (p->cmd1)
		ft_printf("cmd1:      %s\n", p->cmd1);
	else
		ft_printf("cmd1:      %s\n", "(null)");
	if (p->cmd2)
		ft_printf("cmd2:      %s\n", p->cmd2);
	else
		ft_printf("cmd2:      %s\n", "(null)");
	ft_printf("========================\n");
}

void	print_cmdtokens(char **cmdtokens)
{
	int	i;

	if (!cmdtokens)
	{
		ft_printf("No tokens to print.\n");
		return ;
	}
	i = 0;
	while (cmdtokens[i] != NULL)
	{
		ft_printf("token[%d]: %s\n", i, cmdtokens[i]);
		i++;
	}
}

static void	print_npipex_cmds(const t_npipex *npipex)
{
	size_t	i;

	if (npipex->cmds)
	{
		ft_printf("cmds:\n");
		i = 0;
		while (i < npipex->cmd_count)
		{
			if (npipex->cmds[i])
				ft_printf("  [%d]: %s\n", i, npipex->cmds[i]);
			else
				ft_printf("  [%d]: (null)\n", i);
			i++;
		}
	}
	else
		ft_printf("cmds: (null)\n");
}

void	print_npipex(const t_npipex *npipex)
{
	if (!npipex)
	{
		ft_printf("t_npipex pointer is NULL\n");
		return ;
	}
	ft_printf("== npipex ==\n");
	ft_printf("heredoc_on: %d\n", npipex->heredoc_on);
	ft_printf("limiter: %s\n", npipex->limiter);
	ft_printf("input_fd: %d\n", npipex->input_fd);
	ft_printf("output_fd: %d\n", npipex->output_fd);
	ft_printf("cmd_count: %d\n", npipex->cmd_count);
	print_npipex_cmds(npipex);
	ft_printf("============\n");
}
