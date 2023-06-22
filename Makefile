# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 18:07:41 by etlaw             #+#    #+#              #
#    Updated: 2023/06/22 21:57:33 by etlaw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	pushswap
BONUS	=	checker
CC      =   gcc
RM      =   rm -rf
CFLAGS  =   -Wall -Werror -Wextra -g
CSAN  =  #-fsanitize=address -g
INCLUDES    = ./inc
SRC_PATH    = ./srcs/**
BSRC_PATH	= ./bonus/**
OBJ_PATH    = ./obj
LIBFT_PATH	= ./libft

SRCS	= $(shell find $(SRC_PATH) -name "*.c")
BSRCS	= $(shell find $(BSRC_PATH) -name "*.c")

OBJS	= $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRCS))
BOBS	= $(patsubst $(BSRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(BSRCS))

all				:	$(NAME)

bonus			:	$(BONUS)

$(NAME)			:	$(OBJS)
					make -C libft
					$(CC) $(CFLAGS) $(CSAN) $^ -I$(INCLUDES) -lft -L$(LIBFT_PATH) -o $@

$(BONUS)		:	$(BOBS)
					make -C libft
					$(CC) $(CFLAGS) $(CSAN) $^ -I$(INCLUDES) -lft -L$(LIBFT_PATH) -o $@

$(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c ./Makefile $(INCLUDES)
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean			:
					$(MAKE) -C $(LIBFT_PATH) $@
					rm -rf $(OBJ_PATH)


fclean			:	clean
					$(MAKE) -C $(LIBFT_PATH) $@
					rm -rf $(NAME)
					rm -rf $(BONUS)


re				:   fclean all


.PHONY			:	all clean fclean re
