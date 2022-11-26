#!/bin/bash

service mysql start

if [ -d "/var/lib/mysql/$MARIADB_DATABASE" ]
then
	echo -e "${RED} Database [$MARIADB_DATABASE] already exists ${RESET}"
else
	eval "echo \"$(cat ./init_mariadb.sql)\"" | mariadb
fi

service mysql stop

exec "$@"
