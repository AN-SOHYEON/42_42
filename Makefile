# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: san <san@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/05 20:07:18 by san               #+#    #+#              #
#    Updated: 2021/09/07 00:29:28 by san              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCS :=	ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_calloc.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_atoi.c \
			ft_strnstr.c \
			ft_strdup.c \
 			ft_substr.c \
 			ft_strjoin.c \
 			ft_strtrim.c \
 			ft_split.c \
 			ft_itoa.c \
 			ft_strmapi.c \
 			ft_striteri.c \
 			ft_putchar_fd.c \
 			ft_putstr_fd.c \
 			ft_putendl_fd.c \
 			ft_putnbr_fd.c

OBJS	:=	$(SRCS:.c=.o)
AR		:= ar
ARFLAGS	:= -rc
CFLAGS	:=	-Wall -Werror -Wextra
CC		:=	gcc

all	 : $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY	:	clean fclean all re
