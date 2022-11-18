FROM debian:buster

RUN apt-get update && apt-get upgrade -y && \
	apt-get install -y nginx openssl dumb-init

RUN chmod +x /usr/bin/dumb-init

RUN	openssl req -newkey rsa:2048 -days 365 -nodes -x509 \
	-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=san/CN=san.42.fr" \
	-keyout /etc/ssl/private/san42fr.key -out /etc/ssl/certs/san42fr.crt

COPY  ./conf/nginx.conf ./etc/nginx/conf.d/nginx.conf

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "nginx", "-g", "daemon off;"]
