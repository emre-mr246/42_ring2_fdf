# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 09:44:14 by emgul             #+#    #+#              #
#    Updated: 2024/06/13 18:56:33 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper	\
		ft_lstadd_back \
		ft_lstadd_front \
		ft_lstclear \
		ft_lstdelone \
		ft_lstiter \
		ft_lstlast \
		ft_lstmap \
		ft_lstnew \
		ft_lstsize \
		gnl/get_next_line	\
		printf/ft_printf	\
		printf/ft_format_utilities	\
		printf/ft_puthex	\
		printf/ft_putnbr	\
		printf/ft_putstr	\
		printf/ft_putptr	\
		printf/ft_putunsigned
		
NAME	=	libft.a
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR	=	ar rcs
RM	=	rm -f

SRCS	=	$(addsuffix .c, $(FILES))
OBJS =		$(addsuffix .o, $(FILES))

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@make clean

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all re fclean clean
