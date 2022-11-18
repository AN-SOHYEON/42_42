FROM	debian:buster

RUN		apt-get update -y && apt-get upgrade -y && \
		apt-get install -y mariadb-server dumb-init 

RUN		chmod +x /usr/bin/dumb-init && \
		mkdir -p /var/run/mysqld && \
		chown -R mysql:mysql /var/run/mysqld && \
		chmod 777 /var/run/mysqld

RUN 	mkdir -p /var/lib/mysql

COPY	./tools/start_mariadb.sh ./start_mariadb.sh
COPY	./conf/init_mariadb.sql ./init_mariadb.sql	

RUN		chmod +x ./start_mariadb.sh

ENTRYPOINT	["/usr/bin/dumb-init", "--", "bash", "./start_mariadb.sh"]

EXPOSE		3306

CMD			["mysqld", "--bind-address=0.0.0.0"]
