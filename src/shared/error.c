/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 04:05:45 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/20 12:47:50 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	Error Handling
*/

// describe error + system error msg
void	exit_perr(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

// system error
void	exit_strerr(int err_code)
{
	ft_printf("Error: %s\n", strerror(err_code));
	exit(EXIT_FAILURE);
}

// custom error message
void	exit_custom(char *err_msg)
{
	ft_printf("Error: %s\n", err_msg);
	exit(EXIT_FAILURE);
}

// wrapper for process error
void	catch_syserr(int process_status, char *err_msg)
{
	if (process_status == SYSERR_CODE)
		exit_perr(err_msg);
}
