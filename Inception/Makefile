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


# NAME = inception
# COMPOSE_FILE = srcs/docker-compose.yml

# $(NAME) :
# 	sudo docker-compose -f $(COMPOSE_FILE) up --force-recreate --build -d

# all : $(NAME)

# up :
# 	sudo docker-compose -f $(COMPOSE_FILE) up --build -d

# down :
# 	sudo docker-compose -f $(COMPOSE_FILE) down

# restart	:
# 	sudo docker-compose -f $(COMPOSE_FILE) restart

# ps :
# 	sudo docker-compose -f $(COMPOSE_FILE) ps

# logs :
# 	sudo docker-compose -f $(COMPOSE_FILE) logs


# clean :
# 	sudo docker-compose -f $(COMPOSE_FILE) down --remove-orphans --rmi all --volumes

# fclean : clean
# 	rm -rf /Users/ansohyeon/Desktop/SAN/data
# 	sudo docker network prune --force
# 	sodo docker volume prune --force
# 	sudo docker system prune --all --force --volumes

# re :
# 	@$(MAKE) fclean
# 	@$(MAKE) all

# .PHONY : up down restart ps log exec 

NAME = inception
SET_DOMAIN = .set_domain

$(NAME) :
ifeq ("$(wildcard $(SET_DOMAIN))", "")
	sudo chmod 777 /etc/hosts
	sudo echo "127.0.0.1 san.42.fr" >> /etc/hosts
	touch $(SET_DOMAIN)
endif
	sudo mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb ${HOME}/data/hugo
	sudo docker-compose -f srcs/docker-compose.yml up --force-recreate --build -d

all : $(NAME)

up :
	sudo docker-compose -f srcs/docker-compose.yml up --build -d

down :
	sudo docker-compose -f srcs/docker-compose.yml down

.PHONY : restart
restart	:
	sudo docker-compose -f srcs/docker-compose.yml restart

.PHONY : ps
ps :
	sudo docker-compose -f srcs/docker-compose.yml ps

.PHONY : log
log :
	sudo docker-compose -f srcs/docker-compose.yml logs -f ${ct}

.PHONY : exec
exec :
	sudo docker-compose -f srcs/docker-compose.yml exec ${ct} /bin/bash

clean :
	sudo docker-compose -f srcs/docker-compose.yml down --remove-orphans --rmi all --volumes

fclean : clean
	sudo rm -rf ${HOME}/data
	sudo docker network prune --force
	sudo docker volume prune --force
	sudo docker system prune --all --force --volumes
	sudo rm -f $(SET_DOMAIN)

re :
	@$(MAKE) fclean
	@$(MAKE) all
