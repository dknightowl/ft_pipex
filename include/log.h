/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:49:00 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/01 09:49:27 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "struct.h"

void	print_pipex(const t_pipex *p);
void	print_cmdtokens(char **cmdtokens);
void	putstr(const char *str);
void	print_npipex(const t_npipex *pipex);

#endif
