# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 07:09:36 by emgul             #+#    #+#              #
#    Updated: 2024/07/31 08:14:19 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES            = cam draw exit free init init2 keypress main map map_utils matrix parameters projection render utils

BONUS_FILES      = cam draw draw2 exit free init init2 keypress keypress2 keypress3 main map map_utils map_utils2 matrix menu menu2 menu3 parameters projection render rotate utils help

NAME             = fdf
BONUS_NAME		= fdf_bonus

CC               = gcc
CCFLAGS          = -Wall -Wextra -Werror -lXext -lX11 -lm -lbsd -g
MAKEFLAGS        = --no-print-directory
RM               = rm -rf

LIBFT_PATH       = lib/libft/
LIBFT            = $(LIBFT_PATH)libft.a

MLX_PATH         = lib/minilibx/
MLX              = $(MLX_PATH)libmlx.a

FILES_PATH       = src/mandatory/
BONUS_FILES_PATH = src/bonus/
OBJ_DIR          = .obj/

SRCS             = $(addprefix $(FILES_PATH), $(addsuffix .c, $(FILES)))
BONUS_SRCS       = $(addprefix $(BONUS_FILES_PATH), $(addsuffix _bonus.c, $(BONUS_FILES)))

OBJS             = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
BONUS_OBJS       = $(addprefix $(OBJ_DIR), $(notdir $(BONUS_SRCS:.c=.o)))

VALGRIND_PARAMS  = --leak-check=full --show-leak-kinds=all --track-origins=yes

vpath %.c $(FILES_PATH) $(BONUS_FILES_PATH)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(MLX) $(CCFLAGS) -o $(NAME)
	@echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

$(BONUS_NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBFT) $(MLX) $(CCFLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)-== $(BONUS_NAME) created! ==-$(DEFAULT)"

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make $(MAKEFLAGS) -C $(LIBFT_PATH)

$(MLX):
	@make $(MAKEFLAGS) -C $(MLX_PATH)

check-leaks: all
	@make --no-print-directory re
	@echo "$(RED)-==/ LEAK CHECK MODE ON \==-$(DEFAULT)"
	@valgrind $(VALGRIND_PARAMS) ./$(NAME) maps/10-2.fdf

check-leaks-bonus: bonus
	@make --no-print-directory re-bonus
	@echo "$(RED)-==/ LEAK CHECK MODE ON \==-$(DEFAULT)"
	@valgrind $(VALGRIND_PARAMS) ./$(BONUS_NAME) maps/10-2.fdf

check-norm: all
	@norminette src/ lib/libft inc/ | grep -B 1 "Error\|Warning" || echo "$(GREEN)Norme check passed!$(DEFAULT)"
	
clean:
	@$(RM) $(OBJS)
	@$(RM) $(BONUS_OBJS)
	@echo "$(YELLOW)-== all object files deleted! ==-$(DEFAULT)"

fclean: clean libclean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)-== all files deleted! ==-$(DEFAULT)"

libclean:
	@make $(MAKEFLAGS) -C $(LIBFT_PATH) fclean
	@echo "$(BLUE)-== all object files deleted in libraries! ==-$(DEFAULT)"

re: fclean all

re-bonus: fclean bonus

.PHONY: all bonus clean fclean libclean re re-bonus check-leaks check-leaks-bonus check-norm

# ANSI COLOR CODES
DEFAULT = \033[0m
RED     = \033[1;31m
YELLOW  = \033[1;33m
GREEN   = \033[1;32m
BLUE    = \033[1;36m
ORANGE  = \033[38;5;208m