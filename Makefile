# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 13:34:03 by jaguillo          #+#    #+#              #
#    Updated: 2014/11/26 13:34:04 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

H_DIR = h/
C_DIR = srcs/
O_DIR = o/
LIBFT = libft/

FLAGS = -Wall -Wextra -Werror -O2

C_FILES = $(shell ls -1 $(C_DIR) | grep "\.c")

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

LIBFT_C = $(shell ls -1 $(LIBFT)srcs | grep "\.c")

LIBFT_O = $(addprefix $(LIBFT)o/,$(LIBFT_C:.c=.o))

all: $(NAME)

$(NAME): libs $(O_FILES)
	@ar rc $@ $(O_FILES) $(LIBFT_O) && printf "\033[0;32m" || printf "\033[0;31m"
	@printf "%-24s\033[1;30m<<--\033[0;0m\n" "$@"
	@ranlib $@

libs:
	@(make -C $(LIBFT) || (echo "\033[0;31m$(LIBFT)\033[0;0m" && exit 1)) | grep -v "Nothing to be done" || echo "" > /dev/null

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc $(FLAGS) -I $(H_DIR) -I $(LIBFT) -o $@ -c $< && printf "\033[0;0m%-24s\033[1;30m-->>	\033[0;32m$@\033[0;0m\n" "$<" || (printf "\033[0;0m%-24s\033[1;30m-->>	\033[0;31m$@\033[0;0m\n" "$<" && exit 1)

clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@make -C $(LIBFT) clean

fclean: clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null
	@make -C $(LIBFT) fclean

update: fclean
	@git subtree pull --prefix=libft --squash ../libft master -m "Update libft"

re: fclean all

.PHONY: all libs clean fclean update re
