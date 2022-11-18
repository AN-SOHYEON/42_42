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
SET_DOMAIN = .set_domain
LOCAL_VOLUME = /home/san

$(NAME) :
ifeq ("$(wildcard $(SET_DOMAIN))", "")
	sudo chmod 777 /etc/hosts
	sudo echo "127.0.0.1 san.42.fr" >> /etc/hosts
	touch $(SET_DOMAIN)
endif
	sudo mkdir -p ${LOCAL_VOLUME}/data/wordpress ${LOCAL_VOLUME}/data/mariadb
	sudo docker-compose -f srcs/docker-compose.yml up --force-recreate --build -d

all : $(NAME)

up :
	sudo docker-compose -f srcs/docker-compose.yml up --build -d

down :
	sudo docker-compose -f srcs/docker-compose.yml down

.PHONY : ps
ps :
	sudo docker-compose -f srcs/docker-compose.yml ps

.PHONY : log
log :
	sudo docker-compose -f srcs/docker-compose.yml logs -f ${ct}

clean :
	sudo docker-compose -f srcs/docker-compose.yml down --remove-orphans --rmi all --volumes

fclean : clean
	sudo rm -rf ${LOCAL_VOLUME}/data/*
	sudo docker network prune --force
	sudo docker volume prune --force
	sudo docker system prune --all --force --volumes
	rm -f $(SET_DOMAIN)

re :
	@$(MAKE) fclean
	@$(MAKE) all
