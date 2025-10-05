# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 18:58:41 by ikrozas           #+#    #+#              #
#    Updated: 2025/10/05 19:05:00 by ikrozas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCDIR      = include
SRC_DIR     = src

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

INCS        = -I$(INCDIR) -I$(LIBFT_DIR)


SRCS        = $(wildcard $(SRC_DIR)/*.c)
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INCDIR)/pipex.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

norm:
	norminette $(SRC_DIR) $(INCDIR) $(LIBFT_DIR)

.PHONY: all clean fclean re norm