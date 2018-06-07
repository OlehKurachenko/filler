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

all: $(NAME)

src/exports/$(NAME):
	make -C src/exports/ $(NAME)

$(NAME): src/exports/$(NAME)
	cp src/exports/$(NAME) $(NAME)

clean:
	make -C src/exports/ clean

fclean:
	make -C src/exports/ fclean
	rm -f $(NAME)

re: fclean all