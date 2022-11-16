#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

service mysql start

if [ -d "/var/lib/mysql/$MARIADB_DATABASE" ]
then
	echo -e "${RED} Database [$MARIADB_DATABASE] already exists ${RESET}"
else
	eval "echo \"$(cat ./init_mariadb.sql)\"" | mariadb
	# mysqladmin -u root password $MARIADB_ROOT_PASSWORD
fi

service mysql stop

exec "$@"
