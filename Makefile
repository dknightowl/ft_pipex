# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 11:29:35 by dkhoo             #+#    #+#              #
#    Updated: 2025/09/03 12:10:25 by dkhoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

DEBUG_FLAG = -g -O0
CC = cc
CCFLAGS = -Wall -Wextra -Werror -g -O0 $(DEBUG_FLAG)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I$(LIBFT_DIR)/includes

PIPEX_INCLUDES = -Iinclude
SRC_DIR = src
SHARED_DIR = $(SRC_DIR)/shared
SRC_SHARED_FILES =	cleanup.c\
					cmd.c\
					error.c\
					log.c\
					parse.c\
					tokenize.c
SRC_FILES =	main.c\
			pipe.c
SRC_FILES_BONUS = $(SRC_FILES:.c=_bonus.c) heredoc_bonus.c

SHARED = $(addprefix $(SHARED_DIR)/, $(SRC_SHARED_FILES))
SRCS = $(SHARED) $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRCS_B = $(SHARED) $(addprefix $(SRC_DIR)/, $(SRC_FILES_BONUS))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_B:.c=.o)

all: $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(LIBFT_INCLUDES) $(PIPEX_INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus