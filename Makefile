# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 17:32:03 by lauriago          #+#    #+#              #
#    Updated: 2024/03/04 15:46:57 by lauriago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#____________DEFINITION FILES__________#

NAME_SRV = server
NAME_CLIENT = client

BONUS_SRV_NAME = server_bonus
BONUS_CLIENT_NAME = client_bonus

SRC_SRV = server.c
SRC_CLIENT = client.c

SRC_BONUS_SRV = server_bonus.c
SRC_BONUS_CLI = client_bonus.c

SRCS_PATH = ./src/
OBJ_PATH := ./tmp/

OBJ_SRV = $(SRC_SRV:%.c=$(OBJ_PATH)%.o)
OBJ_CLIENT = $(SRC_CLIENT:%.c=$(OBJ_PATH)%.o)

OBJ_SRV_BONUS = $(SRC_BONUS_SRV:%.c=$(OBJ_PATH)%.o)
OBJ_CLIENT_BONUS = $(SRC_BONUS_CLI:%.c=$(OBJ_PATH)%.o)

H_PATH := ./inc
HEADERS = -I$(H_PATH)

#_____________VARIABLES____________#

AR = ar rcs
RM = rm -f
CC = gcc -g
CCFLAGS = -Wall -Wextra -Werror

#____________ORDERS & RULES___________#

#	rule to built all:
all: makelib $(OBJ_PATH) $(NAME_SRV) $(NAME_CLIENT) $(BONUS_SRV_NAME) $(BONUS_CLIENT_NAME)

#	rule to build the lib
makelib:
	$(MAKE) --silent -C libft --no-print-directory

# creates directory for object
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

#	rule to make exectutables
$(NAME_SRV): $(OBJ_SRV)
	$(CC) $(CCFLAGS) $^ -L libft -lft -o $@

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CCFLAGS) $^ -Llibft -lft -o $@

#	rule to make exectutables bonus
$(BONUS_SRV_NAME): $(OBJ_SRV_BONUS)
	$(CC) $(CCFLAGS) $^ -L libft -lft -o $@

$(BONUS_CLIENT_NAME): $(OBJ_CLIENT_BONUS)
	$(CC) $(CCFLAGS) $^ -Llibft -lft -o $@

#	rules to build the objects
$(OBJ_PATH)%.o: $(SRCS_PATH)%.c Makefile libft/libft.a
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

#_____________CLEAN RULES_____________#

clean :
	$(RM) -rd $(OBJ_PATH)
	$(MAKE) --silent -C libft clean

fclean:
	$(RM) -r $(NAME_SRV) $(NAME_CLIENT) $(BONUS_SRV_NAME) $(BONUS_CLIENT_NAME) $(OBJ_PATH)
	$(MAKE) --silent -C libft fclean

re:
	make fclean --silent
	make all --silent
	$(MAKE) all --silent -C libft

#	indicates that this rules aren't files
.PHONY: all clean re fclean
