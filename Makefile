#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 12:41:59 by vpoltave          #+#    #+#              #
#    Updated: 2017/10/25 11:53:39 by vpoltave         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

COR		=	corewar
ASM		=	asm
CC		=	gcc -Wall -Wextra -Werror

LIBFT	=	./libft/libft.a
OBJ		:=	$(patsubst %.c,%.o,$(wildcard *.c))							\
			$(patsubst %.c,%.o,$(wildcard ./cor/virtual_machine/*.c))	\
			$(patsubst %.c,%.o,$(wildcard ./cor/visualisation/*.c))		\
			$(patsubst %.c,%.o,$(wildcard ./cor/instructions/*.c))		\

ASM_OBJ	:=	$(patsubst %.c,%.o,$(wildcard ./assembler/src/*.c))			\
			$(patsubst %.c,%.o,$(wildcard *.c))                         \

.PHONY: libft

all: libft $(ASM) $(COR)

$(COR): $(OBJ)
		$(CC) -o $(COR) $(OBJ) $(LIBFT) -lncurses

$(ASM): $(ASM_OBJ)
		$(CC) -o $(ASM) $(ASM_OBJ) $(LIBFT)

libft:
	@make -C ./libft

%.o : %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	rm -rf $(ASM_OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(COR)
	rm -rf $(ASM)
	make fclean -C ./libft

re: fclean all