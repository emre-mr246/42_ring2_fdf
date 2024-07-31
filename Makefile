# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 07:09:36 by emgul             #+#    #+#              #
#    Updated: 2024/07/31 06:42:11 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			=	cam	draw exit free init init2 keypress main	map	map_utils matrix parameters	projection render utils

BONUS_FILES		=	cam	draw draw2 exit free init init2 keypress keypress2 keypress3 main map map_utils map_utils2 matrix menu menu2 menu3 parameters projection render rotate utils help

NAME			=	fdf

CC				=	gcc
CFLAGS			=	-I $(LIBFT_PATH) -I lib/minilibx-linux/ -g -Wall -Wextra -Werror
MFLAGS			=	-s -C -no-print-directory
AR				=	ar rcs
RM				=	rm -rf

LIBFT_PATH		=	lib/libft/
LIBFT			=	$(LIBFT_PATH)libft.a

MLX_PATH		=	lib/minilibx/
MLX				=	$(MLX_PATH)libmlx.a

FILES_PATH		=	src/mandatory/
BONUS_FILES_PATH=	src/bonus/

SRCS            =   $(addprefix $(FILES_PATH), $(addsuffix .c, $(FILES)))
BONUS_SRCS      =   $(addprefix $(BONUS_FILES_PATH), $(addsuffix _bonus.c, $(BONUS_FILES)))

OBJS            =   $(SRCS:.c=.o)
BONUS_OBJS      =   $(BONUS_SRCS:.c=.o)

VALGRIND_PARAMS	=	--leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

bonus: $(LIBFT) $(MLX) $(BONUS_OBJS)
	@gcc $(BONUS_OBJS) -o $(NAME) $(LIBFT) $(MLX) -lXext -lX11 -lm -lbsd
	@echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@gcc $(OBJS) -o $(NAME) $(LIBFT) $(MLX) -lXext -lX11 -lm -lbsd
	@echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

$(LIBFT):
	@make $(MFLAGS) $(LIBFT_PATH)

$(MLX):
	@make $(MFLAGS) $(MLX_PATH)

check-leaks: all
	@make --no-print-directory re
	@echo "$(RED)-==/ LEAK CHECK MODE ON \==-$(DEFAULT)"
	@valgrind $(VALGRIND_PARAMS) ./$(name) maps/10-2.fdf

check-leaks-bonus: all
	@make --no-print-directory re-bonus
	@echo "$(RED)-==/ LEAK CHECK MODE ON \==-$(DEFAULT)"
	@valgrind $(VALGRIND_PARAMS) ./$(name) maps/10-2.fdf

check-norm: all
	@norminette src/ lib/libft inc/ | grep -B 1 "Error\|Warning" || echo "$(GREEN)Norme check passed!$(DEFAULT)"
	
clean:
	@$(RM) $(OBJS)
	@$(RM) $(BONUS_OBJS)
	@echo "$(YELLOW)-== all object files deleted! -==$(DEFAULT)"

fclean: clean libclean
	@$(RM) $(NAME)
	@echo "$(RED)-== all files deleted! -==$(DEFAULT)"

libclean:
	@make $(MFLAGS) $(LIBFT_PATH) fclean
	@echo "$(BLUE)-== all object files deleted in libraries! -==$(DEFAULT)"

re: fclean all

re-bonus: fclean bonus

.PHONY: all clean fclean re bonus libclean re-bonus check-leaks check-leaks-bonus check-norm

# ANSI COLOR CODES
DEFAULT = \033[0m
RED = \033[1;31m
YELLOW = \033[1;33m
GREEN = \033[1;32m
BLUE = \033[1;36m
ORANGE = \033[38;5;208m
