NAME		=	valid
NAME_B		=	valid_bonus

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

FILES_M		= 	${shell find ./src_mandatory -name "*.c"}
FILES_L		= 	${shell find ./src_lib -name "*.c"}
SRC_M		= 	$(FILES_M) $(FILES_L)
OBJ_M		=	$(patsubst %.c,%.o,$(SRC_M))
LIB			=	
HEAD_M		=	-I./src_mandatory/validation.h  -I./src_lib/libft.h

#FILES_B	= 	${shell find ./src_bonus -name "*.c"}
#SRC_B		= 	$(FILES_B) $(FILES_L)
#OBJ_B		=	$(patsubst %.c,%.o,$(SRC_B))
# HEAD_B	=	-I./src_bonus/minishell.h -I./libft/libft.h

.PHONY:		all clean fclean re rec bonus rebonus

all:		$(NAME)

$(NAME):	$(OBJ_M) ./src_mandatory/validation.h
			@$(CC) $(LIB) $(CFLAGS) $(HEAD_M) $(OBJ_M) -o $(NAME)
			@echo "\033[32m[$(NAME)] mandatory part compiled.\033[0m"

bonus:		$(NAME_B)

$(NAME_B):	$(OBJ_B) ./src_bonus/pipex_bonus.h
			@$(CC) $(LIB) $(CFLAGS) $(HEAD_B) $(OBJ_B) -o $(NAME_B)
			@echo "\033[32m[$(NAME_B)] bonus part compiled.\033[0m"

%.o:		%.c ./src_lib/*.c ./src_mandatory/*.c
			@$(CC) $(LIB) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@$(RM) $(OBJ_M)
			@$(RM) $(OBJ_B)
			@echo "\033[32m[$(NAME)] removed object files.\033[0m"

fclean:		
			@$(RM) $(OBJ_M)
			@$(RM) $(OBJ_B)
			@$(RM) $(NAME)
			@$(RM) $(NAME_B)
			@echo "\033[33m[$(NAME)] & [$(NAME_B)] removed object and executable files.\033[0m"

re:			fclean all

rec:		fclean all
			@$(RM) $(OBJ_M)
			@$(RM) $(OBJ_B)
			@echo "\033[33m[$(NAME)] removed object files.\033[0m"

rebonus:	fclean bonus
