# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: san <san@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 13:13:49 by san               #+#    #+#              #
#    Updated: 2022/09/23 13:13:51 by san              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inception
COMPOSE_FILE = srcs/docker-compose.yml

$(NAME) :
	sudo docker-compose -f $(COMPOSE_FILE) up --force-recreate --build -d

all : $(NAME)

up :
	sudo docker-compose -f $(COMPOSE_FILE) up --build -d

down :
	sudo docker-compose -f $(COMPOSE_FILE) down

restart	:
	sudo docker-compose -f $(COMPOSE_FILE) restart

ps :
	sudo docker-compose -f $(COMPOSE_FILE) ps

logs :
	sudo docker-compose -f $(COMPOSE_FILE) logs


clean :
	sudo docker-compose -f $(COMPOSE_FILE) down --remove-orphans --rmi all --volumes

fclean : clean
	rm -rf /Users/ansohyeon/Desktop/SAN/data
	# sudo docker network prune --force
	sodo docker volume prune --force
	sudo docker system prune --all --force --volumes

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : up down restart ps log exec 