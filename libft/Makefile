# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tapperce <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 12:06:41 by tapperce          #+#    #+#              #
#    Updated: 2017/02/01 08:07:56 by gsotty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAG = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
	  ft_lstmap.c ft_lstnew.c ft_lstputback.c ft_memalloc.c ft_memccpy.c \
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strnequ.c \
	  ft_strnew.c ft_strncpy.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
	  ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
	  ft_toupper.c ft_nb_word.c ft_len_word.c ft_absolute.c ft_sqrt.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAG) -c $< -I.

clean:
	rm -Rf libft.h.gch
	rm -rf *.o

fclean: clean
	rm -Rf $(NAME)

re: fclean all
