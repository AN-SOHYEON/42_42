# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: san <san@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 15:00:42 by san               #+#    #+#              #
#    Updated: 2022/08/05 15:00:43 by san              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cast02

FLAGS	=	-Wall -Wextra -Werror -std=c++98
CC		=	c++

SRC		=	main.cpp Base.cpp

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
