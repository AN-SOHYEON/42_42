NAME	=ft_container_test

CXX		= c++ 
FLAGS	= -Wall -Werror -Wextra -std=c++98

INC_PATH	= ./includes/
SRC_PATH	= ./src/

# primary
SRC_FILE = main #vector_test
SRC_TEST = src/ft_stl.cpp

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
	@$(CXX) $(FLAGS) -I$(INC_PATH) $(SRC_TEST) -o TEST -O3 -g #-fsanitize=address -g3
	# @./TEST

tclean	:
	@echo "remove test..."
	@$(RM) TEST

.PHONY :
	all clean fclean re test tclean
