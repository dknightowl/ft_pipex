/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:39:59 by dkhoo             #+#    #+#             */
/*   Updated: 2025/08/14 13:10:12 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// print_npipex(&npipex);
int	main(int argc, char *argv[], char *envp[])
{
	t_npipex	npipex;

	if (argc < 5)
		exit_custom(FEW_ARGS_ERR);
	parse_npipex(argc, argv, &npipex);
	execute_npipe(&npipex, envp);
	return (0);
}
