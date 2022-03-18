NAME	= push_swap
CC		= gcc
FLG		= -Wall -Wextra -Werror

SRC		= main.c d_list.c d_list2.c libft0.c validation.c
OBJ		= $(SRC:.c=.o)


all: $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME): $(OBJ)
	$(CC) $(FLG) -o $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLG) -c $<

.PHONY: all clean fclean re