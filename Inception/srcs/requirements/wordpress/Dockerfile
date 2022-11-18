

FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y && \
	apt-get install -y php7.3 php-fpm php-cli wget curl vim php-mysql dumb-init mariadb-client

RUN	chmod +x /usr/bin/dumb-init && mkdir -p /run/php && \
	mkdir -p /var/www/html

RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp && \
	chmod +x /usr/bin/wp

WORKDIR		/var/www/html

COPY		./conf/init.sh /tmp/init.sh

RUN			chmod +x /tmp/init.sh

EXPOSE		9000

ENTRYPOINT	["/usr/bin/dumb-init", "--", "bash", "/tmp/init.sh"]
