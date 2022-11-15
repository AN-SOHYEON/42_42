#!/bin/sh

echo "in start_mariadb.sh"

service mysql start

if ! [ -d "/var/lib/mysql/$MARIADB_DATABASE" ]; then
	echo "Creating $MARIADB_DATABASE...."
	eval "echo \"$(cat ./init_mariadb.sql)\"" | mariadb
else
	echo "$MARIADB_DATABASE already exists"
fi

service mysql stop

exec "$@"