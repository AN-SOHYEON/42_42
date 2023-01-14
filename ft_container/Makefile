NAME	=ft_container_test

CC		= c++ 
FLAGS	= -Wall -Werror -Wextra -std=c++98

INC_PATH	= ./includes/ 
SRC_PATH	= ./src/
BUILD_PATH	= ./build/

# primary
SRC_FILE = main #vector_test

SRC = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(SRC_FILE)))
# OBJ=$(SRC:$(SRC_PATH)%.o=$(BUILD_PATH)%.o)
OBJ = $(addsuffix .o, $(SRC_FILE))

RM=/bin/rm -rf



# Object directory generation
$(BUILD_PATH)	:
	@mkdir $(BUILD_PATH)

%.o: %.cpp
	@echo "$(NAME) compile..."
	@$(CC) $(FLAGS) -I $(INC_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -I $(INC_PATH) -o $(NAME) $(OBJ)

all	: $(NAME)

clean	:
	@echo "remove..."
	@$(RM) $(OBJ)
	@$(RM) $(BUILD_PATH)

fclean	: clean
	@echo "remove all"
	@$(RM) $(NAME) 

re	: fclean all

.PHONY :
	all clean fclean re
