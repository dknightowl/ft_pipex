/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize-utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:39:41 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/06 17:02:31 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Utility functions for tokenizing command string into argument vector to be
//	passed to execve

int	append_char(char *token, int *append_idx, char append_c)
{
	if ((*append_idx + 1) >= MAX_ARG_LEN)
		return (0);
	token[(*append_idx)++] = append_c;
	token[*append_idx] = '\0';
	return (1);
}

int	advance_on_backslash(char *s, int *idx)
{
	if (s[*idx] == '\\')
	{
		(*idx)++;
		if (s[*idx] == '\0')
			return (0);
	}
	return (1);
}

int	append_subquote(char *token, int *t_idx, char *s, int *s_idx)
{
	char	*append_quote;
	int		a_idx;

	append_quote = parse_quoted_token(s, s_idx, s[*s_idx]);
	if (!append_quote)
		return (0);
	a_idx = 0;
	while (append_quote[a_idx] != '\0')
	{
		if (!append_char(token, t_idx, append_quote[a_idx]))
		{
			free(append_quote);
			return (0);
		}
		a_idx++;
	}
	free(append_quote);
	return (1);
}

int	advance_to_next_token(char *cmd, int *s_idx, int t_idx)
{
	while (ft_isspace(cmd[*s_idx]))
		(*s_idx)++;
	if (cmd[*s_idx] == '\0' || t_idx > (MAX_ARGS - 1))
		return (0);
	return (1);
}

char	*parse_token(char *cmd, int *idx)
{
	if (cmd[*idx] == '"' || cmd[*idx] == '\'')
		return (parse_quoted_token(cmd, idx, cmd[*idx]));
	return (parse_unquoted_token(cmd, idx));
}
