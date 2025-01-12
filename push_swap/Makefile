# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:19:42 by tat-nguy          #+#    #+#              #
#    Updated: 2025/01/01 12:34:17 by tat-nguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libft
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Source Files
DIR_SRCS	= srcs

# Paths and Files
SRCS_PUSH_SWAP = $(wildcard $(DIR_SRCS)/push_swap/*.c $(DIR_SRCS)/shared/*.c)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

SRCS_CHECKER = $(wildcard $(DIR_SRCS)/checker/*.c $(DIR_SRCS)/shared/*.c)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

# Include
INCLUDES	= -I includes

# Compiler and Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# Targets
all:	$(LIBFT) push_swap

bonus:	$(LIBFT) checker

# Build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Build push_swap
push_swap:	$(OBJS_PUSH_SWAP)
	@$(CC) $(CFLAGS) $(INCLUDES) -o push_swap $(OBJS_PUSH_SWAP) -L$(LIBFT_DIR) -lft

# Build checker
checker: $(OBJS_CHECKER)
	@$(CC) $(CFLAGS) $(INCLUDES) -o checker $(OBJS_CHECKER) -L$(LIBFT_DIR) -lft
	
# Clean
clean:
	@$(RM) $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	@$(RM) push_swap checker
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus push_swap checker
