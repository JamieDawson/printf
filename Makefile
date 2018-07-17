# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadawson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 16:05:37 by jadawson          #+#    #+#              #
#    Updated: 2018/07/16 23:04:40 by jadawson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -c
NAME = libftprintf.a

PRINTF_SRC_DIR := ./src/
PRINTF_SRC = 	ft_printf.c \
	  			parse.c \
	  			str_funct.c \
	 			type_check.c \
	 			base_functions.c\
				wide_handle.c\
				width_handle.c\
				confirm_fln.c\
				str_funct_2.c\
				str_funct_3.c\
				length_apply.c\
				flag_apply.c\
				flag_apply_num_1.c
PRINTF_OBJ = $(patsubst %.c, %.o, $(PRINTF_SRC))

LIBFT_SRC_DIR = ./libft/
LIBFT_H = $(LIBFT_SRC_DIR)  
LIBFT_SRC = ft_strlen.c \
	  		ft_numlen.c \
	  		ft_strnew.c \
	  		ft_memalloc.c \
	  		ft_bzero.c \
	  		ft_putchar.c \
	  		ft_putnbr.c \
	  		ft_putstr.c\
			ft_atoi.c\
			ft_strrev.c

LIBFT_OBJ = $(patsubst %.c, %.o, $(LIBFT_SRC))

SRC = $(LIBFT_SRC) $(PRINTF_SRC)

OBJ = $(SRC:%.c=%.o)

COMPILED = $(LIBFT_OBJ) $(PRINTF_OBJ)

all: $(NAME)

$(NAME): $(COMPILED) 
	ar rc $(NAME) $(COMPILED)
	ranlib $(NAME)
	echo "made" $(NAME)

$(PRINTF_OBJ): %.o: $(PRINTF_SRC_DIR)%.c
	$(CC) -c $(CFLAGS) -I $(LIBFT_H) -I. -I inc $< -o $@
$(LIBFT_OBJ): %.o: $(LIBFT_SRC_DIR)%.c
	$(CC) -c $(CFLAGS) -I $(LIBFT_H) -I. -I inc $< -o $@
$(OBJ_DIR):
	mkdir obj
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
