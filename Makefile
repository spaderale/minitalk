# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 02:12:20 by abroslav          #+#    #+#              #
#    Updated: 2025/11/10 02:16:32 by abroslav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = server.c
SRC_CLIENT = client.c

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT):
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

clean:
	rm -f *.o

fclean: clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all
