
FROM debian:buster

RUN	apt-get update
RUN apt-get upgrade
RUN apt-get install -y mariadb-server dumb-init
# RUN apk add mariadb mariadb-client dumb-init
RUN			chmod +x /usr/bin/dumb-init


WORKDIR	/

RUN	mkdir -p /var/run/mysqld
RUN	chown -R mysql:mysql /var/run/mysqld
# chown user:group /file/path
RUN	chmod 777 /var/run/mysqld

RUN 		mkdir -p /var/lib/mysql
RUN			chown -R mysql:mysql /var/lib/mysql

COPY ./conf/init_mariadb.sql ./init_mariadb.sql
COPY ./tools/start_mariadb.sh ./start_mariadb.sh

RUN chmod +x ./start_mariadb.sh

#ENTRYPOINT [ "sh", "-c", "./start_mariadb.sh" ]
# ENTRYPOINT [ "sh", "./start_mariadb.sh" ]
ENTRYPOINT ["/usr/bin/dumb-init", "--", "bash", "./start_mariadb.sh"]

# CMD ["bash", "./start_mariadb.sh"]
CMD ["mysqld", "--bind-addresss=0.0.0.0"]



# mariadb dockerfile
# https://infraadmin.tech/blog/docker-alpine-linux%EC%97%90-wordpress-mariadb-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B02/


# https://jjongwoo.tistory.com/29
# https://gafani.tistory.com/entry/MariaDBMySQL-%EC%9B%90%EA%B2%A9%EC%97%90%EC%84%9C-%EC%A0%91%EA%B7%BC%EC%9D%B4-%EA%B0%80%EB%8A%A5%ED%95%98%EB%8F%84%EB%A1%9D-%EC%84%A4%EC%A0%95%ED%95%98%EA%B8%B0

########순서
# - apt update && upgrade
# - mysql config 파일 copy
# - 	- user, port, bind ip adress 설정
# - mysql dump파일 COPY
# - shell script 파일 COPY	
# 	- mysql db에 테이블과 유저 생성하고 설정
# 	- mysql에 mysql dump 파일 적용
# 	- mysql exec으로 pid1 실행
# - shell script파일 실행

