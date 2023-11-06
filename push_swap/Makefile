# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:03:05 by rroussel          #+#    #+#              #
#    Updated: 2023/02/16 16:15:30 by rroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_CYAN=\033[0;36m
COLOUR_END=\033[0m

SRCS :=	./push_swap.c\
	./sorting/sorting_5.c\
	./sorting/sorting_big_stack.c\
	./sorting/sorting_3.c\
	./utils/oper_swap.c\
	./utils/tools_list.c\
	./utils/oper_push.c\
	./utils/oper_rev_rotate.c\
	./utils/oper_rotate.c\
	./parsing/parsing.c\
	./parsing/parsing2.c

B_SRCS := ./bonus/checker.c\
	./utils/oper_swap.c\
	./utils/tools_list.c\
	./utils/oper_push.c\
	./utils/oper_rev_rotate.c\
	./utils/oper_rotate.c\
	./parsing/parsing.c\
	./parsing/parsing2.c

LIBFT := ./libft/libft.a
NAME := push_swap
B_NAME := checker
CC := clang
HEADERS := ./includes/push_swap.h
B_HEADERS := ./includes/checker.h
CFLAGS := -Wall -Wextra -Werror
OBJS := $(SRCS:.c=.o)
B_OBJS := $(B_SRCS:.c=.o)
RM := /bin/rm -f

.ONESHELL:

$(NAME):	 $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "↪ Finish, $(COLOUR_BLUE)push_swap$(COLOUR_END) $(COLOUR_GREEN)compiled$(COLOUR_END)"

$(B_NAME):	$(LIBFT) $(B_OBJS)
	@echo "Compiling checker..."
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(B_NAME)
	@echo "↪ Finish, $(COLOUR_BLUE)checker$(COLOUR_END) $(COLOUR_GREEN)compiled$(COLOUR_END)"

$(LIBFT):
	@echo "$(COLOUR_CYAN)
		██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ 
		██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗
		██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝
		██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ 
		██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     
		╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     by rroussel$(COLOUR_END)"
	@echo "Compiling libft..."
	$(MAKE) -C libft bonus

                                                                           

%.o : %.c $(HEADERS)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -I ./includes -o $@
	@sleep .05
	@printf "\033[1A"
	@printf "\033[K"

all:	$(NAME)

bonus:	$(B_NAME) $(B_HEADERS)

clean:
	@echo "Cleaning files..."
	@$(RM) $(OBJS) $(B_OBJS)
	@$(MAKE) -C libft clean
	@echo "↪ Finish, $(COLOUR_BLUE)files$(COLOUR_END) $(COLOUR_RED)cleaned$(COLOUR_END)"

fclean:	clean
	@echo "Cleaning binaries..."
	@$(RM) $(NAME) $(B_NAME)
	@$(MAKE) -C libft fclean
	@echo "↪ Finish, $(COLOUR_BLUE)binaries$(COLOUR_END) $(COLOUR_RED)cleaned$(COLOUR_END)"

re:	fclean all
	@echo "↪ Finish, $(COLOUR_BLUE)re-make$(COLOUR_END) $(COLOUR_GREEN)done$(COLOUR_END)"

.PHONY: bonus clean fclean re all
