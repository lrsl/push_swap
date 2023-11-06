# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 12:07:20 by rroussel          #+#    #+#              #
#    Updated: 2023/02/14 12:07:20 by rroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

SRCS := ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
B_SRCS := ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsort.c ft_lstdelnode_by_value.c ft_lstdelnode_by_address.c get_next_line.c get_next_line_utils.c
NAME := libft.a
CC := gcc
HEADERS := libft.h get_next_line.h
CFLAGS := -Wall -Wextra -Werror
OBJS := $(SRCS:.c=.o)
B_OBJS := $(B_SRCS:.c=.o)
RM := /bin/rm -f
COMP := ar rc


$(NAME):	$(OBJS)
	@$(COMP) $(NAME) $(OBJS)

%.o : %.c $(HEADERS)
	@echo "↪ Compiling $<"
	@$(CC) $(CFLAGS) -c $< -I ./ -o $@
	@printf "\033[1A"
	@printf "\033[K"

all:	$(NAME)

bonus:	$(OBJS) $(B_OBJS)
	@$(COMP) $(NAME) $(OBJS) $(B_OBJS)
	@echo "↪ Finish, $(COLOUR_BLUE)libft$(COLOUR_END) $(COLOUR_GREEN)compiled$(COLOUR_END)"
	@echo "Compiling push_swap..."

clean:
	@$(RM) $(OBJS) $(B_OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: bonus clean fclean re all
