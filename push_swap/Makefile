NAME	:= push_swap	#근데 이걸 = 으로 바꾸면 쓰레기 파일이 생긴다 왜지? 아 아닌가 새로운 파일을 만들려고 할 때마다 뭔가 생기는 건가?

CC		= gcc
FLG		= -Wall -Wextra -Werror

SRC		= main.c d_list.c d_list2.c libft0.c validation.c operation_p.c operation_s.c operation_r.c operation_rr.c
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