NAME	=ft_container_test

CXX		= c++ 
FLAGS	= -Wall -Werror -Wextra -std=c++98

INC_PATH	= ./includes/
SRC_PATH	= ./src/

# primary
SRC_FILE = main
SRC_TEST = src/ft_test.cpp

SRC = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(SRC_FILE)))
OBJ = $(SRC:.cpp=.o)

RM=/bin/rm -rf

%.o: %.cpp
	@echo "$(NAME) compile..."
	@$(CXX) $(FLAGS) -I$(INC_PATH) -O3 -o $@ -c $<

$(NAME): $(OBJ)
	@$(CXX) $(FLAGS) -I$(INC_PATH) -o $(NAME) $(OBJ)

all	: $(NAME)

clean	:
	@echo "remove..."
	@$(RM) $(OBJ)

fclean	: clean
	@echo "remove all"
	@$(RM) $(NAME) 

re	: fclean all

test:
	@$(CXX) $(FLAGS) -I$(INC_PATH) $(SRC_TEST) -o TEST -O3 -g 

tclean	:
	@echo "remove test..."
	@$(RM) TEST

.PHONY :
	all clean fclean re test tclean
