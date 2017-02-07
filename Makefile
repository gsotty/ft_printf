# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsotty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 15:44:40 by gsotty            #+#    #+#              #
#    Updated: 2017/02/07 13:58:06 by gsotty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAG = -Wall -Wextra -Werror

SRC = check_flag.c check_lenght.c check_precision.c check_specifier.c \
	  check_width.c ft_intmax_t_itoa_base.c write_u.c \
	  ft_intmax_t_itoa_base_m.c test_1.c write_um.c ft_itoa_base.c write_c.c \
	  write_x.c ft_long_itoa_base.c write_cm.c write_xm.c write_d_and_i.c \
	  ft_remalloc.c write_dm.c ft_unsigned_itoa.c write_o.c \
	  ft_unsigned_itoa_base.c write_om.c ft_unsigned_itoa_base_m.c write_p.c \
	  ft_unsigned_long_itoa_base.c write_pourcent.c \
	  ft_unsigned_long_itoa_base_m.c write_s.c \
	  ft_wcstombs.c write_sm.c ft_atoi.c ft_bzero.c ft_itoa.c ft_memcpy.c \
	  ft_putstr.c ft_strcat.c ft_strjoin.c ft_strlen.c ft_strnew.c \
	  ft_memalloc.c ft_memset.c ft_putnbr.c ft_putchar.c write_buf.c \
	  ft_strdup.c ft_itoa_int_min.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAG) -c $< -I.

clean:
	rm -Rf $(OBJ)
	rm -Rf ft_printf.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
