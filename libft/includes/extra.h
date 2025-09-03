/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:51:09 by dkhoo             #+#    #+#             */
/*   Updated: 2025/09/01 15:49:58 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H

# include "libft.h"

long	ft_strtol(const char *str, char **endptr, int base);
int		ft_isupper(int c);
int		ft_islower(int c);
void	ft_free2d(void **arr);
int		ft_isspace(int c);

#endif