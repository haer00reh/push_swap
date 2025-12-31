# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haer-reh <haer-reh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 20:41:17 by haer-reh          #+#    #+#              #
#    Updated: 2025/12/31 15:52:20 by haer-reh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
CFLAGS = -Wall -Wextra -Werror
CC = cc

FILES = push_swap.c simple_sort.c utils/additional_utils.c  utils/ErrorsUtils.c  utils/ListUtils.c  utils/Utils.c \
		ops/StackOperations0.c  ops/StackOperations2.c  ops/StackOperations.c \
		algorithms/algorithms.c  algorithms/calculations.c  algorithms/lis.c  algorithms/pushing.c  algorithms/rotations1.c  algorithms/rotations.c

B_FILES = bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/c_StackOperations.c bonus/c_StackOperations0.c bonus/c_StackOperations2.c \
			utils/ErrorsUtils.c utils/ListUtils.c utils/additional_utils.c utils/Utils.c

OBJ = $(FILES:.c=.o)
B_OBJ = $(B_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJ)
	$(CC) $(B_OBJ) -o $(B_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(B_OBJ)
fclean: clean
	rm -f $(NAME) $(B_NAME)
re: fclean all