/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:27:23 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/03 20:08:23 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Tokenize command string into argument vector to be passed to execve

static int	append_char(char *token, int *append_idx, char append_c)
{
	if ((*append_idx + 1) >= MAX_ARG_LEN)
		return (0);
	token[(*append_idx)++] = append_c;
	token[*append_idx] = '\0';
	return (1);
}

static char	*parse_quoted_token(char *s, int *idx, char q_char)
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
		if (s[*idx] == '\\')
		{
			(*idx)++;
			if (s[*idx] == '\0')
				break ;
		}
		if (!append_char(token, &t_idx, s[*idx]))
		{
			free(token);
			return (NULL);
		}
		(*idx)++;
	}
	if (s[*idx] != q_char)
	{
		free(token);
		return (NULL);
	}
	(*idx)++;
	return (token);
}

static char	*parse_unquoted_token(char *s, int *idx)
{
	char	*token;
	int		t_idx;
	char	*append_quote;
	int		a_idx;

	token = malloc(MAX_ARG_LEN);
	if (!token)
		return (NULL);
	token[0] = '\0';
	t_idx = 0;
	while (s[*idx] != '\0' && !ft_isspace(s[*idx]))
	{
		if (s[*idx] == '"' || s[*idx] == '\'')
		{
			append_quote = parse_quoted_token(s, idx, s[*idx]);
			if (!append_quote)
			{
				free(token);
				return (NULL);
			}
			a_idx = 0;
			while (append_quote[a_idx] != '\0')
			{
				if (!append_char(token, &t_idx, append_quote[a_idx]))
				{
					free(token);
					free(append_quote);
					return (NULL);
				}
				a_idx++;
			}
			free(append_quote);
			continue ;
		}
		if (s[*idx] == '\\')
		{
			(*idx)++;
			if (s[*idx] == '\0')
				break ;
		}
		if (!append_char(token, &t_idx, s[*idx]))
		{
			free(token);
			return (NULL);
		}
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
		while (ft_isspace(cmd[s_idx]))
			s_idx++;
		if (cmd[s_idx] == '\0' || t_idx > (MAX_ARGS - 1))
			break ;
		if (cmd[s_idx] == '"' || cmd[s_idx] == '\'')
			token = parse_quoted_token(cmd, &s_idx, cmd[s_idx]);
		else
			token = parse_unquoted_token(cmd, &s_idx);
		if (!token)
		{
			tokens[t_idx] = NULL;
			ft_free2d((void **) tokens);
			return (NULL);
		}
		tokens[t_idx] = token;
		t_idx++;
	}
	tokens[t_idx] = NULL;
	return (tokens);
}
