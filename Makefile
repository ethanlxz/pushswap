# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 18:07:41 by etlaw             #+#    #+#              #
#    Updated: 2023/04/26 19:25:48 by etlaw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	pushswap
CC      =   gcc
RM      =   rm -rf
CFLAGS  =   -Wall -Werror -Wextra -g
CSAN  =  #-fsanitize=address -g
INCLUDES    = ./inc
SRC_PATH    = ./srcs/**
OBJ_PATH    = ./obj
LIBFT_PATH	= ./libft

# SRCS	= $(wildcard ./srcs/*.c)
# SRCS	= $(wildcard $(SRC_PATH)/*.c)
SRCS	= $(shell find ./srcs/ -name "*.c")

# OBJS	= $(addprefix $(OBJ_PATH)/,$(patsubst %.c,%.o,$(notdir $(SRCS))))
OBJS	= $(patsubst srcs/%.c,$(OBJ_PATH)%.o, $(SRCS))

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					make -C libft
					$(CC) $(CFLAGS) $(CSAN) $^ -I$(INCLUDES) -lreadline -lncurses -lft -L$(LIBFT_PATH) -o $@

$(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c* ./inc/*.h ./Makefile | $(OBJ_PATH) 
					$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@

$(OBJ_PATH)		:
					mkdir -p $(OBJ_PATH)


clean			:
					$(MAKE) -C $(LIBFT_PATH) $@
					rm -rf $(OBJ_PATH)


fclean			:	clean
					$(MAKE) -C $(LIBFT_PATH) $@
					rm -rf $(NAME)


re				:   fclean all


.PHONY			:	all clean fclean re
