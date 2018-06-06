# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okurache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 17:48:13 by okurache          #+#    #+#              #
#    Updated: 2018/06/06 17:48:15 by okurache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = okurache.filler

CC = gcc -Wall -Wextra -Werror

LC_ADD = ar -q

SRC_DIR = src

OBJ_DIR = obj

SRC_N =	main.c \
		filler_run_game.c \
		filler_make_step.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_N:.c=.o))

IMPORTS_PATH = ../../imports

LIBFT_PATH = $(IMPORTS_PATH)/okurache_libft
LIBFTPRITNF_PATH = $(IMPORTS_PATH)/okurache_ft_printf
LIBFTIN_PATH = $(IMPORTS_PATH)/okurache_libftin

LIBFT_A = libft.a
LIBFTPRITNF_A = libftprintf.a
LIBFTIN_A = libftin.a

LIBALL = $(LIBFT_PATH)/$(LIBFT_A) $(LIBFTPRITNF_PATH)/$(LIBFTPRITNF_A) $(LIBFTIN_PATH)/$(LIBFTIN_A)

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/fd_reader

$(NAME): $(LIBALL) $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBALL)

clean: libclean
	rm -rf $(OBJ_DIR)

fclean: libfclean clean
	rm -f $(NAME)

re: fclean all

$(LIBFT_PATH)/$(LIBFT_A):
	make -C $(LIBFT_PATH)/ all

$(LIBFTPRITNF_PATH)/$(LIBFTPRITNF_A):
	make -C $(LIBFTPRITNF_PATH)/ all

$(LIBFTIN_PATH)/$(LIBFTIN_A):
	make -C $(LIBFTIN_PATH)/ all

libclean:
	make -C $(LIBFT_PATH)/ clean
	make -C $(LIBFTPRITNF_PATH)/ clean
	make -C $(LIBFTIN_PATH)/ clean

libfclean:
	make -C $(LIBFT_PATH)/ fclean
	make -C $(LIBFTPRITNF_PATH)/ fclean
	make -C $(LIBFTIN_PATH)/ fclean

libre:
	make -C $(LIBFT_PATH)/ re
	make -C $(LIBFTPRITNF_PATH)/ re
	make -C $(LIBFTIN_PATH)/ re
