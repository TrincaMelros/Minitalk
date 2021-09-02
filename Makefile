# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malmeida <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 13:41:45 by malmeida          #+#    #+#              #
#    Updated: 2021/09/02 17:15:24 by malmeida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	--quiet

			# Library Name #
NAME		=
CLIENT		=	client
SERVER		=	server

			# Libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

			# Mandatory Variables #
SRC_CLIENT	=	./srcs/client.c
SRC_SERVER	=	./srcs/server.c

			# Compiling Variables #
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I./includes -I$(LIBFT_DIR) -I$(PRINTF_DIR)
RM		= rm -f

			# Color Variables #
GREEN		= \e[0;32m
RED			= \e[0;31m
YELLOW		= \e[0;33m
RESET		= \e[0m

all: $(SERVER) $(CLIENT)

$(NAME): all

$(CLIENT): $(LIBFT) $(SRC_CLIENT)
	@ $(CC) $(CFLAG) $(SRC_CLIENT) $(LIBFT) -o $(CLIENT)
	@printf "[$(GREEN)SUCCESS$(RESET)] Client compiled.\n"

$(SERVER): $(LIBFT) $(SRC_SERVER)
	@ $(CC) $(CFLAG) $(SRC_SERVER) $(LIBFT) -o $(SERVER)
	@printf "[$(GREEN)SUCCESS$(RESET)] Server compiled.\n"

$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "[$(YELLOW)SUCCESS$(RESET)] Executables removed.\n"

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "[$(YELLOW)SUCCESS$(RESET)] Libraries removed.\n"
	@printf "[$(YELLOW)SUCCESS$(RESET)] Executables removed.\n"

re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		mandatory

m:	mandatory
b: 	bonus
