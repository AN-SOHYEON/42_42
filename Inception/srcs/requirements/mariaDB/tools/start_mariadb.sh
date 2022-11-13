#!/bin/sh

echo "in start_mariadb.sh"
if [ ! -d "/run/mysqld" ]; then
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
fi


service mysql start

if [ -d "/var/lib/mariadb/$MARIADB_DATABASE" ]
# -d : 파일이 디렉토리면 참
then 
	echo -e "$MARIADB_DATABASE already exists"
else
	eval "echo \"$(cat ./init_mariadb.sql)\"" | mariadb
fi

service mysql stop

exec "$@"