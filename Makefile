# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 21:49:39 by eshintan          #+#    #+#              #
#    Updated: 2024/01/30 05:21:53 by eshintan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	include

RM		= rm -f

SRCS 		= ft_printf.c

OBJS 		= $(SRCS:.c=.o)

libft		= libft/libft.a

$(NAME):	$(OBJS)
				make -C libft
					ar rcs $(NAME)	$(OBJS) $(libft)
				
all:		$(NAME)

clean:
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re: 		fclean $(NAME)

.PHONY: 	all clean fclean re