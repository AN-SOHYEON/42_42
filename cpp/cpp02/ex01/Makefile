# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: san <san@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 16:41:15 by san               #+#    #+#              #
#    Updated: 2022/07/29 16:41:21 by san              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fix01

FLAGS	=	-Wall -Wextra -Werror -std=c++98
CC		=	c++

SRC		=	main.cpp Fixed.cpp

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
