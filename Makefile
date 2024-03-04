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

SRC_SRV = server.c
SRC_CLIENT = client.c

SRCS_PATH = ./src/
OBJ_PATH := ./tmp/

OBJ_SRV = $(SRC_SRV:%.c=$(OBJ_PATH)%.o)
OBJ_CLIENT = $(SRC_CLIENT:%.c=$(OBJ_PATH)%.o)

H_PATH := ./inc
HEADERS = -I$(H_PATH)

#_____________VARIABLES____________#

AR = ar rcs
RM = rm -fr
CC = gcc -g
CCFLAGS = -Wall -Wextra -Werror

#____________ORDERS & RULES___________#

#	rule to built all:
all: makelib $(OBJ_PATH) $(NAME_SRV) $(NAME_CLIENT)

#	rule to build the lib
makelib:
	$(MAKE) --silent -C libft --no-print-directory

# creates directory for object
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

#	rule to make exectutables
$(NAME_SRV): $(OBJ_SRV)
	$(CC) $(CCFLAGS) $^ -Llibft -lft -o $@

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CCFLAGS) $^ -Llibft -lft -o $@

#	rules to build the objects
$(OBJ_PATH)%.o: $(SRCS_PATH)%.c Makefile libft/libft.a
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

#_____________CLEAN RULES_____________#

clean :
	$(RM) $(OBJ_PATH)
	$(MAKE) --silent -C libft clean

fclean:
	$(RM) $(NAME_SRV) $(NAME_CLIENT) $(OBJ_PATH)
	$(MAKE) --silent -C libft fclean

re:
	make fclean --silent
	make all --silent
	$(MAKE) all --silent -C libft

#	indicates that this rules aren't files
.PHONY: all clean re fclean
