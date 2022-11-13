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

all:
	docker-compose -p inception --project-directory srcs up -d

stop:
	docker-compose -p inception --project-directory srcs stop

list:
	@echo "\033[0;34mList of available containers:\033[0m"
	@docker ps
	@echo "\033[0;34mImages:\033[0m"
	@docker images ls
	@echo "\033[0;34mNetworks:\033[0m"
	@docker network ls
	@echo "\033[0;34mVolumes:\033[0m"
	@docker volume ls

clean:
	@docker stop $$(docker ps -qa) || true
	@docker rm $$(docker ps -qa) || true
	@docker rmi -f $$(docker images -qa) || true
	@docker volume rm $$(docker volume ls -q) || true
	@docker network rm $$(docker network ls -q) 2>/dev/null || true

fclean: clean
	docker system prune -a


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
