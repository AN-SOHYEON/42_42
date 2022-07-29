# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: san <san@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 12:48:00 by san               #+#    #+#              #
#    Updated: 2022/07/29 12:48:03 by san              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	violence

FLAGS	=	-Wall -Wextra -Werror -std=c++98
CC		=	c++

SRC		=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

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
