# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: san <san@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 16:23:49 by san               #+#    #+#              #
#    Updated: 2022/08/02 16:23:51 by san              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	=	animal02

FLAGS	=	-Wall -Wextra -Werror -std=c++98
CC		=	c++

SRC		=	main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJ		=	${SRC:%.cpp=%.o}

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o :		%.cpp
			$(CC) $(FLAGS) -c $<

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
