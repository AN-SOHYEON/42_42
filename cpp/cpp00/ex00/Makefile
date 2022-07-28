# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: san <san@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 13:50:07 by san               #+#    #+#              #
#    Updated: 2022/07/28 13:52:28 by san              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

FLAGS	=	-Wall -Wextra -Werror -std=c++98 -MD
CC		=	c++

SRC		=	megaphone.cpp

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

-include ${SRC:%.cpp=%.d}