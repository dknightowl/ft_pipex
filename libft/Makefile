# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 09:05:13 by dkhoo             #+#    #+#              #
#    Updated: 2025/09/01 15:51:33 by dkhoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library
NAME = libft.a

# Compiler and flags
CC		=	cc
CCFLAGS	=	-Wall -Wextra -Werror

# Directories
INCLUDES_DIR	=	includes
SRCS_DIR		=	src
EXTRA_DIR		=	$(SRCS_DIR)/extra
LIBFT_DIR		=	$(SRCS_DIR)/libft
GNL_DIR			=	$(SRCS_DIR)/get_next_line
PRINTF_DIR		=	$(SRCS_DIR)/ft_printf

HEADER_FILES	=	extra.h libft.h get_next_line_bonus.h ft_printf.h

# Source files
EXTRA_SRC_FILES		=		ft_islower.c\
							ft_isupper.c\
							ft_strtol.c\
							ft_free2d.c\
							ft_isspace.c
LIBC_SRC_FILES		=		ft_isalpha.c\
							ft_isdigit.c\
							ft_isalnum.c\
							ft_isascii.c\
							ft_isprint.c\
							ft_strlen.c\
							ft_memset.c\
							ft_bzero.c\
							ft_memcpy.c\
							ft_memmove.c\
							ft_strlcpy.c\
							ft_strlcat.c\
							ft_toupper.c\
							ft_tolower.c\
							ft_strchr.c\
							ft_strrchr.c\
							ft_strncmp.c\
							ft_memchr.c\
							ft_memcmp.c\
							ft_strnstr.c\
							ft_atoi.c\
							ft_calloc.c\
							ft_strdup.c
LIBFT_EXTRA_SRC_FILES	=	ft_substr.c\
							ft_strjoin.c\
							ft_strtrim.c\
							ft_split.c\
							ft_itoa.c\
							ft_strmapi.c\
							ft_striteri.c\
							ft_putchar_fd.c\
							ft_putstr_fd.c\
							ft_putendl_fd.c\
							ft_putnbr_fd.c
MANDATORY_SRC_FILES	=		$(LIBC_SRC_FILES) $(LIBFT_EXTRA_SRC_FILES)
BONUS_SRC_FILES		=		ft_lstnew_bonus.c\
							ft_lstadd_front_bonus.c\
							ft_lstsize_bonus.c\
							ft_lstlast_bonus.c\
							ft_lstadd_back_bonus.c\
							ft_lstdelone_bonus.c\
							ft_lstclear_bonus.c\
							ft_lstiter_bonus.c\
							ft_lstmap_bonus.c
GNL_SRC_FILES		=		get_next_line_bonus.c\
							get_next_line_utils_bonus.c
PRINTF_SRC_FILES	=		ft_printf.c\
							ft_printf_c.c\
							ft_printf_i.c\
							ft_printf_p.c\
							ft_printf_s.c\
							ft_printf_x.c\
							ft_printf_rawf.c\
							ft_printf_utils.c\
							ft_format_utils.c\
							ft_general_utils.c\
							ft_build_int_output.c\
							ft_build_ptr_output.c\
							ft_build_str_output.c\
							ft_set_format.c\
							ft_ptoa.c\
							ft_utohex.c
ALL_SRC_FILES		=		$(MANDATORY_SRC_FILES) $(BONUS_SRC_FILES) $(GNL_SRC_FILES) $(PRINTF_SRC_FILES) $(EXTRA_SRC_FILES)

# Object files
MANDATORY_OBJ_FILES	=	$(MANDATORY_SRC_FILES:.c=.o)
BONUS_OBJ_FILES		=	$(BONUS_SRC_FILES:.c=.o)
GNL_OBJ_FILES		=	$(GNL_SRC_FILES:.c=.o)
PRINTF_OBJ_FILES	=	$(PRINTF_SRC_FILES:.c=.o)
ALL_OBJ_FILES		=	$(ALL_SRC_FILES:.c=.o)

# Compilation files
HEADERS				=	$(addprefix $(INCLUDES_DIR)/, $(HEADER_FILES))
SRCS				=	$(addprefix $(EXTRA_DIR)/, $(EXTRA_SRC_FILES))\
						$(addprefix $(LIBFT_DIR)/, $(MANDATORY_SRC_FILES))\
						$(addprefix $(LIBFT_DIR)/, $(BONUS_SRC_FILES))\
						$(addprefix $(GNL_DIR)/, $(GNL_SRC_FILES))\
						$(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC_FILES))
OBJS 				=	$(addprefix $(SRCS_DIR)/, $(ALL_OBJ_FILES))

# make all
all: $(NAME)

# Create library
# 	r: replace/add object files
# 	c: create library if it does not exist
# 	s: add an index to make it easier for the linker to find symbols
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile source files into object files
# 	-c : compile without main
# 	-o : output name
$(SRCS_DIR)/%.o: $(EXTRA_DIR)/%.c $(HEADERS)
	$(CC) $(CCFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(SRCS_DIR)/%.o: $(LIBFT_DIR)/%.c $(HEADERS)
	$(CC) $(CCFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(SRCS_DIR)/%.o: $(GNL_DIR)/%.c $(HEADERS)
	$(CC) $(CCFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(SRCS_DIR)/%.o: $(PRINTF_DIR)/%.c $(HEADERS)
	$(CC) $(CCFLAGS) -I$(INCLUDES_DIR) -c $< -o $@


# Clean object files only
clean:
	rm -f $(OBJS)

# Clean object files and library
fclean: clean
	rm -f $(NAME)

# Clean and rebuild everything
re: fclean all

test: $(SRCS) $(HEADERS) test.c
	$(CC) $(CCFLAGS) $(SRCS) test.c -o test.out -I$(INCLUDES_DIR)
	./test.out

.PHONY: all clean fclean re test
