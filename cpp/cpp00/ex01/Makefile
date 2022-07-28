# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: san <san@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 13:57:44 by san               #+#    #+#              #
#    Updated: 2022/07/28 13:57:50 by san              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

FLAGS	=	-Wall -Wextra -Werror -std=c++98
CC		=	c++

SRC		=	Contact.cpp main.cpp PhoneBook.cpp

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
