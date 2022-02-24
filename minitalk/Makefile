NAME = 
CLIENT = client
SERVER = server

SRC_CLIENT = client.c ft_atoi.c ft_putnbr.c ft_bzero.c
SRC_SERVER = server.c ft_atoi.c ft_putnbr.c ft_bzero.c

OBG_CLIENT = $(SRC_CLIENT:.c=.o)
OBG_SERVER = $(SRC_SERVER:.c=.o)

GCC_FLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(SERVER) $(CLIENT)

clean :
	rm -f $(OBG_SERVER) $(OBG_CLIENT) 

fclean : clean
	rm -f $(CLIENT) $(SERVER)

re : fclean all

$(CLIENT) : $(OBG_CLIENT) 
	$(CC) $(GCC_FLAGS) -o $(CLIENT) $(OBG_CLIENT) 

$(SERVER) : $(OBG_SERVER)
	$(CC) $(GCC_FLAGS) -o $(SERVER) $(OBG_SERVER)

%.o : %.c
	$(CC) $(GCC_FLAGS) -c $<

.PHONY : clean fclean all re