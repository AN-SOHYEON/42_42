
FROM alpine:3.15

RUN	apt-get update
RUN apt-get -y install mariadb-server


COPY ./conf/init_mariadb.sql /home/
COPY ./tools/start_mariadb.sh /home/

ENTRYPOINT [ "sh" "/home/start_mariadb.sh" ]


# CMD ["service", "mysql start"]




# mariadb dockerfile
# https://infraadmin.tech/blog/docker-alpine-linux%EC%97%90-wordpress-mariadb-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B02/