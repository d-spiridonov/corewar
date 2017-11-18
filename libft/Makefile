#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/22 11:35:22 by vpoltave          #+#    #+#              #
#    Updated: 2017/10/25 09:15:55 by yzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
objects :=	$(patsubst %.c,%.o,$(wildcard src/ft_printf/*.c)) 		\
			$(patsubst %.c,%.o,$(wildcard src/libft/*.c))			\
			$(patsubst %.c,%.o,$(wildcard src/get_next_line/*.c))	\

all: $(NAME)

$(NAME) : $(objects)
	ar rc $(NAME) $(objects)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o
	rm -rf src/ft_printf/*.o
	rm -rf src/get_next_line/*.o
	rm -rf src/libft/*.o
	rm -rf *~

fclean: clean
	rm -rf $(NAME)

re: fclean all
