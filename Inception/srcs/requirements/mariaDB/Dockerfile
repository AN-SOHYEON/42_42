FROM		debian:buster

RUN			apt-get update -y
RUN			apt-get upgrade -y
RUN			apt-get -y install mariadb-server vim sudo procps dumb-init

RUN			chmod +x /usr/bin/dumb-init

WORKDIR		/

RUN			mkdir -p /var/run/mysqld
RUN			chown -R mysql:mysql /var/run/mysqld
RUN			chmod 777 /var/run/mysqld

COPY		./tools/start_mariadb.sh ./start_mariadb.sh
COPY		./conf/init_mariadb.sql ./init_mariadb.sql

RUN			chmod +x ./start_mariadb.sh

# Handle Every Signal Correctly by Dumb Init to PID 1
ENTRYPOINT	["/usr/bin/dumb-init", "--", "bash", "./start_mariadb.sh"]

CMD			["mysqld", "--bind-address=0.0.0.0"]
