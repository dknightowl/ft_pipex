/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:27:23 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/06 17:04:10 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Tokenize command string into argument vector to be passed to execve

char	*parse_quoted_token(char *s, int *idx, char q_char)
{
	char	*token;
	int		t_idx;

	token = malloc(MAX_ARG_LEN);
	if (!token)
		return (NULL);
	token[0] = '\0';
	t_idx = 0;
	(*idx)++;
	while (s[*idx] != '\0' && s[*idx] != q_char)
	{
		if (!advance_on_backslash(s, idx))
			break ;
		if (!append_char(token, &t_idx, s[*idx]))
			return (free(token), NULL);
		(*idx)++;
	}
	if (s[*idx] != q_char)
		return (free(token), NULL);
	(*idx)++;
	return (token);
}

char	*parse_unquoted_token(char *s, int *idx)
{
	char	*token;
	int		t_idx;

	token = malloc(MAX_ARG_LEN);
	if (!token)
		return (NULL);
	token[0] = '\0';
	t_idx = 0;
	while (s[*idx] != '\0' && !ft_isspace(s[*idx]))
	{
		if (s[*idx] == '"' || s[*idx] == '\'')
		{
			if (!append_subquote(token, &t_idx, s, idx))
				return (free(token), NULL);
			continue ;
		}
		if (!advance_on_backslash(s, idx))
			break ;
		if (!append_char(token, &t_idx, s[*idx]))
			return (free(token), NULL);
		(*idx)++;
	}
	return (token);
}

char	**tokenize_cmd(char *cmd)
{
	char	**tokens;
	int		s_idx;
	char	*token;
	int		t_idx;

	tokens = malloc(MAX_ARGS * sizeof(char *));
	if (!tokens)
		return (NULL);
	s_idx = 0;
	t_idx = 0;
	while (cmd[s_idx] != '\0')
	{
		if (!advance_to_next_token(cmd, &s_idx, t_idx))
			break ;
		token = parse_token(cmd, &s_idx);
		if (!token)
		{
			tokens[t_idx] = NULL;
			return (ft_free2d((void **) tokens), NULL);
		}
		tokens[t_idx] = token;
		t_idx++;
	}
	tokens[t_idx] = NULL;
	return (tokens);
}
