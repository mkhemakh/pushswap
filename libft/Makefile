# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 16:44:25 by mkhemakh          #+#    #+#              #
#    Updated: 2019/12/31 18:01:59 by mkhemakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# Library Name #
NAME		=	libft.a

	# Main (Mandatory) Variables #
LIBFT_DIR	=	./
SRC			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c \
				ft_strlen.c ft_strdup.c ft_str_isconvertible.c\
				ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
				ft_strlcpy.c ft_strncmp.c ft_atoi.c \
				ft_capitalize.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_toupper.c ft_tolower.c ft_isint.c ft_str_isnumeric.c\
				ft_strmapi.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strcmp.c\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_print_words.c ft_strrev.c ft_split_whitespaces.c ft_sort_table.c \
				ft_putnbr.c ft_strcpy.c ft_strmap.c ft_strnew.c \
				ft_striteri.c ft_strequ.c ft_swap.c\
				ft_striter.c ft_putstr.c ft_putchar.c ft_strcat.c ft_lstremove.c\
				ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstadd_back.c \
				ft_lstnew.c ft_lstmap.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
				$(STACK) $(GNL)
OBJ			=	$(SRC:.c=.o)

	# stack Variables #
STACK_DIR	=	./stack
STACK		=	stack/ft_stack_new.c stack/ft_stack_add_front.c \
				stack/ft_stack_add_back.c stack/ft_stack_size.c \
				stack/ft_stack_last.c stack/ft_stack_first.c \
				stack/ft_stack_remove.c stack/ft_stack_print.c \
				stack/ft_stack_clear.c stack/ft_stack_is_sorted.c \
				stack/ft_stack_max_value.c stack/ft_stack_min_value.c \
				stack/ft_stack_is_duplicate.c stack/ft_stack_sort.c \
				stack/ft_stack_duplicate.c stack/ft_stack_get.c \
				stack/ft_stack_median.c stack/ft_stack_has_bigger.c \
				stack/ft_stack_find.c
STACK_O		=	$(STACK:.c=.o)

	# get_next_line Variables #
GNL_DIR		=	./get_next_line
GNL			=	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_O		=	$(GNL:.c=.o)

	# Includes flag for compilation #
INC			= 	-I$(LIBFT_DIR) -I$(STACK_DIR) -I$(GNL_DIR)

	# Compiling Variables #
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
CLIB		=	ar -rc
RM			=	rm -f

	# Debugger #
ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

	# Fsanitize #
ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=address -g
endif

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

%.o: %.c
	@ $(CC) $(CFLAG) $(D_FLAG) -c $< -o $(<:.c=.o) $(INC)

all: $(NAME)

$(NAME): $(OBJ) 
	@ $(CLIB) $(NAME) $(OBJ) 

bonus: clean $(LIST_O)
	@ $(CLIB) $(NAME) $(LIST_O)

stack: clean $(STACK_O)
	@ $(CLIB) $(NAME) $(STACK_O)

get_next_line: clean $(GNL_O)
	@ $(CLIB) $(NAME) $(GNL_O)

gnl: get_next_line

clean:
	@ $(RM) $(OBJ) $(LIST_O) $(STACK_O) $(GNL_O)

fclean:
	@ $(RM) $(OBJ) $(LIST_O) $(STACK_O) $(GNL_O)
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus info
