

FROM debian:buster

RUN apt-get update -y 
RUN apt-get upgrade -y
RUN apt-get install -y php7.3 php-fpm php-cli wget curl vim php-mysql dumb-init
	#php-mbstring php-xml sendmail 
RUN apt-get install -y mariadb-client


RUN			chmod +x /usr/bin/dumb-init

RUN			mkdir -p /var/www/wordpress
RUN			mkdir -p /run/php
RUN			mkdir -p /var/www/html

RUN			wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# RUN			mv wp-cli.phar /usr/bin/wp
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp

RUN			chmod +x /usr/bin/wp

WORKDIR		/var/www/wordpress

COPY		./conf/init.sh /tmp/init.sh

RUN			chmod +x /tmp/init.sh

EXPOSE		9000


ENTRYPOINT	["/usr/bin/dumb-init", "--", "bash", "/tmp/init.sh"]
# 출처: https://epicarts.tistory.com/159

# php-fpm : https://server-talk.tistory.com/329 
# 도커를 이용한 프로젝트 진행 참고 자료 : https://velog.io/@du0928/42DoProject-%EA%B0%9C%EB%B0%9C%EC%9D%BC%EC%A7%80



# https://conory.com/blog/42956
# https://velog.io/@du0928/PHP-fpm
# https://stackoverflow.com/questions/37313780/how-can-i-start-php-fpm-in-a-docker-container-by-default
# https://stackoverflow.com/questions/57741106/run-php-php7-3-fpm-sock-is-missing-in-docker-debian-container
# https://www.digitalocean.com/community/tutorials/understanding-and-implementing-fastcgi-proxying-in-nginx

# https://www.digitalocean.com/community/tutorials/understanding-and-implementing-fastcgi-proxying-in-nginx
# https://myjeeva.com/php-fpm-configuration-101.html#pool-directives



#########3순서
# - apt update && upgrade
# - php, php-mysql, php-fpm 설치
# - wordpress.tar 파일 add
# - wordpress 디렉토리 nginx 유저이름으로 권한 설정
# - wp-config 파일 (wordpress 설정파일) copy
# - www.config 파일 (php-fpm 설정파일) copy
# - php-fpm 실행