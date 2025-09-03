NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

INCDIR	= incude
SRC_DIR 	= src

LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRCS 		= $(wildcard &(SRC_DIR)/*.c)
OBJS 		= $(SRCS:.c=.o)

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INCDIR)/pipex.h
	$(CC) $(CFLAGS) -I $(INCDIR)-c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

norm:
	norminette $(SRCS) $(INCDIR)/*.h $(LIBFT_DIR) 	pipex.h

.PHONY: all clean fclean re norm