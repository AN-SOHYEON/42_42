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
# 	docker-compose -f $(COMPOSE_FILE) up --force-recreate --build -d

# all : $(NAME)

# up :
# 	docker-compose -f $(COMPOSE_FILE) up --build -d

# down :
# 	docker-compose -f $(COMPOSE_FILE) down

# restart	:
# 	docker-compose -f $(COMPOSE_FILE) restart

# ps :
# 	docker-compose -f $(COMPOSE_FILE) ps

# logs :
# 	docker-compose -f $(COMPOSE_FILE) logs


# clean :
# 	docker-compose -f $(COMPOSE_FILE) down --remove-orphans --rmi all --volumes

# fclean : clean
# 	rm -rf /Users/ansohyeon/Desktop/SAN/data
# 	docker network prune --force
# 	sodo docker volume prune --force
# 	docker system prune --all --force --volumes

# re :
# 	@$(MAKE) fclean
# 	@$(MAKE) all

# .PHONY : up down restart ps log exec 

NAME = inception
SET_DOMAIN = .set_domain
LOCAL_VOLUME = /Users/ansohyeon/Desktop/SAN

$(NAME) :
ifeq ("$(wildcard $(SET_DOMAIN))", "")
	chmod 777 /etc/hosts
	echo "127.0.0.1 san.42.fr" >> /etc/hosts
	touch $(SET_DOMAIN)
endif
	mkdir -p ${LOCAL_VOLUME}/data/wordpress ${LOCAL_VOLUME}/data/mariadb
	sudo docker-compose -f srcs/docker-compose.yml up --force-recreate --build -d

all : $(NAME)

up :
	docker-compose -f srcs/docker-compose.yml up --build -d

down :
	docker-compose -f srcs/docker-compose.yml down

.PHONY : restart
restart	:
	docker-compose -f srcs/docker-compose.yml restart

.PHONY : ps
ps :
	docker-compose -f srcs/docker-compose.yml ps

.PHONY : log
log :
	docker-compose -f srcs/docker-compose.yml logs -f ${ct}

.PHONY : exec
exec :
	docker-compose -f srcs/docker-compose.yml exec ${ct} /bin/bash

clean :
	docker-compose -f srcs/docker-compose.yml down --remove-orphans --rmi all --volumes

fclean : clean
	rm -rf ${LOCAL_VOLUME}/data/*
	docker network prune --force
	docker volume prune --force
	docker system prune --all --force --volumes
	rm -f $(SET_DOMAIN)

re :
	@$(MAKE) fclean
	@$(MAKE) all
