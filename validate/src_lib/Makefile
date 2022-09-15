# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kthucydi <kthucydi@student.21-school.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 17:23:26 by kthucydi          #+#    #+#              #
#    Updated: 2021/10/15 17:23:40 by kthucydi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEAD = libft.h

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c  ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
	  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS) -c

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	$(LIB) $(OBJ)
	$(RANLIB)
	echo "[INFO] Library [$(NAME)] created"

%.o: %.c
	gcc $(CFLAGS) -c $<

bonus: $(OBJ_BONUS) $(HEAD)
	$(LIB) $(OBJ_BONUS)
	$(RANLIB)
	echo "[INFO] Bonus Library [$(NAME)] created"

clean:
	$(REMOVE) $(OBJ) $(OBJ_BONUS)
	echo "[INFO] Removed objects"

fclean: clean
	$(REMOVE) $(NAME)
	echo "[INFO] Library and objects removed "

re: fclean all

.PHONY: all clean fclean re
