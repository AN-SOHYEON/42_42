# 엔진엑스를 다운받아주는 패키지를 다운받는 것부터 시작하는 쉘스크립트를 만들어라 

FROM alpine:3.16
RUN apt-get update
RUN apt-get install nginx
# sudo add-apt-repository ppa:ondrej/nginx-stable -y && sudo apt update
# sudo apt install nginx-core nginx-common nginx nginx-full
# https://ko.linuxcapable.com/how-to-install-nginx-with-lets-encrypt-tls-ssl-on-ubuntu-20-04/

CMD [ "start" "nginx" ]