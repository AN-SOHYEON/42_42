

FROM alpine:3.15

RUN apt-get update -y 
RUN apt-get -y install php7.3 php-fpm php-cli wget curl php-mysql php-mbstring php-xml sendmail vim

# php7.3 
# php-fpm 
# php-cli 
# wget 
# curl 
# php-mysql 
# php-mbstring 
# php-xml 



RUN wget https://wordpress.org/latest.tar.gz && \
tar -xvf latest.tar.gz && \
mv /wordpress/* /var/www/html/ && \
chown -R www-data:www-data /var/www/html && \ 
rm -r /wordpress latest.tar.gz

RUN apt-get -y install mariadb-client


# 출처: https://epicarts.tistory.com/159

# php-fpm : https://server-talk.tistory.com/329 
# 도커를 이용한 프로젝트 진행 참고 자료 : https://velog.io/@du0928/42DoProject-%EA%B0%9C%EB%B0%9C%EC%9D%BC%EC%A7%80
