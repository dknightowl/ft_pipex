/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 06:05:56 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/11 11:54:25 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// For testing only
// # include <stdio.h>
// # include <string.h>

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

# define ERROR -1
# define LOWERCASE_HEX_DIGITS "0123456789abcdef"
# define UPPERCASE_HEX_DIGITS "0123456789ABCDEF"
# define PRINTF_FLAGS_LIMIT 5
# define IDX_NOT_FOUND -1

typedef enum e_sign_state
{
	SIGNED,
	UNSIGNED
}	t_sign_state;

typedef enum e_char_case
{
	LOWERCASE,
	UPPERCASE
}	t_char_case;

typedef struct s_format
{
	char	flags[PRINTF_FLAGS_LIMIT];
	int		width;
	int		precision;
	char	type;
}	t_fmt;

/*
	Defines the valid number types for the t_fmt struct
*/
typedef enum e_format_number_type
{
	WIDTH,
	PRECISION
}	t_fmtnumtype;

/* printer functions */
int		ft_printf(const char *format, ...);
int		ft_printf_c(t_fmt *fmt, char arg);
int		ft_printf_i(t_fmt *fmt, int arg, t_sign_state sign);
int		ft_printf_p(t_fmt *fmt, void *p);
int		ft_printf_s(t_fmt *fmt, char *arg);
int		ft_printf_x(t_fmt *fmt, unsigned int uint_n, t_char_case c_case);
int		ft_printf_rawf(char *fmt_s);

/* ft_printf_utils.c */
int		ft_print_char(const char c);
int		ft_print_str(const char *s);

/* formatting functions */
char	*ft_build_int_output(t_fmt *fmt, int arg, t_sign_state sign);
char	*ft_build_ptr_output(t_fmt *fmt, char *ptr_str);
char	*ft_build_str_output(t_fmt *fmt, char *arg);

void	ft_set_format(char *fmt_s, t_fmt *fmt);

/* ft_format_utils.c */
int		ft_is_valid_type(char c);
int		ft_is_valid_flag(char c);
char	*ft_next_fmt_str(const char *format, unsigned int start_idx);
t_fmt	*ft_new_format(void);

/* ft_general_utils.c */
void	ft_free_all(void *ptr1, ...);
char	*ft_new_padding(char pad_char, int len);
int		ft_idxof_c(const char c, const char *s);
char	*ft_ctoa(int c);

/* other general utilities */
char	*ft_ptoa(const void *ptr);
char	*ft_utohex(unsigned int uint_n, t_char_case is_upper);

#endif