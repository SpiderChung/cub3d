# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 19:58:58 by scornhol          #+#    #+#              #
#    Updated: 2022/07/01 21:03:22 by scornhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

HEAD	=	libft.h

SRC		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c ft_atod.c ft_free_split.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

SRC_B	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJ		=	${SRC:.c=.o}

OBJ_B	=	${SRC_B:.c=.o}

CFLAGS	=	-Wall -Werror -Wextra

CC		=	gcc $(CFLAGS) -c

LIB		=	ar rc $(NAME)

RANLIB	=	ranlib $(NAME)

REMOVE	=	rm -f

.PHONY: all clean fclean re bonus rebonus

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	@$(LIB) $(OBJ)
	@$(RANLIB)
	@#echo "\033[32mLibrary [$(NAME)] created"

%.o: %.c
	@gcc $(CFLAGS) -c $<

bonus: $(OBJ_B) $(HEAD)
	@$(LIB) $(OBJ_B)
	@$(RANLIB)
	@#echo "\033[32mBonus Library [$(NAME)] created"

clean:
	@$(REMOVE) $(OBJ) $(OBJ_B)
	@#echo "\033[32mRemoved [$(NAME)] objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@#echo "\033[32mLibrary [$(NAME)] and objects removed "

re: fclean all

rebonus: fclean bonus
