# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 02:12:20 by abroslav          #+#    #+#              #
#    Updated: 2025/11/11 14:55:12 by abroslav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf.a

SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c
SRC_SERVER_BONUS = server_bonus.c utils_bonus.c
SRC_CLIENT_BONUS = client_bonus.c utils_bonus.c
SRC_PRINTF = $(PRINTF_DIR)/*.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

all: $(PRINTF) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(PRINTF) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(PRINTF) -o $(NAME_SERVER_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	$(RM) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(RM) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
