# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:54:32 by tblaase           #+#    #+#              #
#    Updated: 2022/09/14 19:02:47 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/
LIBFT_DIR	=	libft/
LIBMLX_DIR	=	mlx/

SRC_FILES	=	${shell find ./src -name "*.c"}
OBJ_FILES	=	$(patsubst %.c,%.o, $(notdir $(SRC_FILES)))
INC_FILES	= 	$(addprefix $(LIBFT_DIR), cub3d.h)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT		=	$(addprefix $(LIBFT_DIR), libft.a)
LIBMLX		=	$(addprefix $(LIBMLX_DIR), libmlx.a)

LINK			=	-L $(LIBFT_DIR) -lft -L $(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(LIBFT) $(LIBMLX) $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(OBJ) $(LINK) -lm -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(FLAGS) -I $(LIBMLX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

$(LIBFT):
	@echo "$(YELLOW)Compiling $(LIBFT_DIR) library...$(RESET)"
	@make -C $(LIBFT_DIR)

$(LIBMLX):
	@echo "$(YELLOW)Compiling $(LIBMLX_DIR) library...$(RESET)"
	@make -C $(LIBMLX_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBMLX_DIR) clean
	@if [ -d "$(OBJ_DIR)" ]; then \
			rm -rf $(OBJ_DIR); \
			echo "$(BLUE)Deleting all objects from /cub3d...$(RESET)"; else \
			echo "No objects to remove from /cub3D."; \
	fi;

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME) from /cub3d...$(RESET)"; else \
		echo "No Executable to remove from /cub3D."; \
	fi;

re: fclean all

norm:
	@echo $(G)Checking Norminette...$(X)
	@norminette libft src include | grep Error | egrep --color '.*Error!|$$' || true
	@echo $(G)Done$(X)

.PHONY: all clean fclean re norm


RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K