# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malmeida <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 17:29:02 by malmeida          #+#    #+#              #
#    Updated: 2021/04/23 14:22:37 by malmeida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft.a
SRCS		= ./srcs/ft_atoi.c			\
			  ./srcs/ft_bzero.c			\
			  ./srcs/ft_calloc.c		\
			  ./srcs/ft_isalnum.c		\
			  ./srcs/ft_isalpha.c		\
			  ./srcs/ft_isascii.c		\
			  ./srcs/ft_isdigit.c		\
			  ./srcs/ft_isprint.c		\
			  ./srcs/ft_memccpy.c		\
			  ./srcs/ft_memchr.c		\
			  ./srcs/ft_memcmp.c		\
			  ./srcs/ft_memcpy.c		\
			  ./srcs/ft_memmove.c		\
			  ./srcs/ft_memset.c		\
			  ./srcs/ft_strchr.c		\
			  ./srcs/ft_strdup.c		\
			  ./srcs/ft_strlcat.c		\
			  ./srcs/ft_strlcpy.c		\
			  ./srcs/ft_strlen.c		\
			  ./srcs/ft_strncmp.c		\
			  ./srcs/ft_strnstr.c		\
			  ./srcs/ft_strrchr.c		\
			  ./srcs/ft_tolower.c		\
			  ./srcs/ft_toupper.c		\
			  ./srcs/ft_substr.c		\
			  ./srcs/ft_strjoin.c		\
			  ./srcs/ft_strtrim.c		\
			  ./srcs/ft_split.c			\
			  ./srcs/ft_itoa.c			\
			  ./srcs/ft_strmapi.c		\
			  ./srcs/ft_putchar_fd.c	\
			  ./srcs/ft_putstr_fd.c		\
			  ./srcs/ft_putendl_fd.c	\
			  ./srcs/ft_putnbr_fd.c		\

OBJS		= $(SRCS:.c=.o)

BONUS		= ./srcs_bonus/ft_lstnew.c			\
			  ./srcs_bonus/ft_lstadd_front.c	\
			  ./srcs_bonus/ft_lstsize.c			\
			  ./srcs_bonus/ft_lstlast.c			\
			  ./srcs_bonus/ft_lstadd_back.c		\
			  ./srcs_bonus/ft_lstdelone.c		\
			  ./srcs_bonus/ft_lstclear.c		\
			  ./srcs_bonus/ft_lstiter.c			\
			  ./srcs_bonus/ft_lstmap.c			\

BONUS_OBJS	= $(BONUS:%.c=%.o)

CFLAGS		= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

$(OBJ):		$(SRCS)
			gcc $(CFLAGS) $(FILES) -I

clean:
		/bin/rm -f $(OBJS) $(BONUS_OBJS)

fclean:	clean
		/bin/rm -f $(NAME)

re: fclean all

bonus:	$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

