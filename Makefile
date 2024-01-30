# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 21:49:39 by eshintan          #+#    #+#              #
#    Updated: 2024/01/30 09:07:03 by eshintan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	include

RM		= rm -f

SRCS 		= ft_printf.c ft_printf_utils.c

OBJS 		= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
					ar rcs $(NAME)	$(OBJS)
				
all:		$(NAME)

clean:
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re: 		fclean $(NAME)

.PHONY: 	all clean fclean re