# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 18:10:30 by abroslav          #+#    #+#              #
#    Updated: 2025/11/10 21:58:47 by abroslav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf.a

SRC		=	ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putnbr_pf.c \
			ft_putuint_pf.c ft_aux_pf.c ft_puthex_low_pf.c ft_puthex_upp_pf.c \
			ft_putptr_pf.c

OBJS	=	$(SRC:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
AR		=	ar rcs


$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
