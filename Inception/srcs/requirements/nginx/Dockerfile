# 엔진엑스를 다운받아주는 패키지를 다운받는 것부터 시작하는 쉘스크립트를 만들어라 

FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y nginx
# sudo add-apt-repository ppa:ondrej/nginx-stable -y && sudo apt update
# sudo apt install nginx-core nginx-common nginx nginx-full
# https://ko.linuxcapable.com/how-to-install-nginx-with-lets-encrypt-tls-ssl-on-ubuntu-20-04/
RUN apt-get -y install openssl dumb-init

RUN chmod +x /usr/bin/dumb-init

# ssl 인증서 생성
RUN	openssl req -newkey rsa:2048 -days 365 -nodes -x509 \
	-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=san/CN=san.42.fr" \
	#-keyout localhost.dev.key -out localhost.dev.crt
	-keyout /etc/ssl/private/server.key -out /etc/ssl/certs/server.crt

# config 파일과 sh 파일 컨테이너 내부로 copy
COPY  ./conf/nginx.conf ./etc/nginx/conf.d/nginx.conf


# ENTRYPOINT [ "/usr/bin/dumb-init", "--", "/my/script " ]


# CMD [ "start" "nginx" ]
CMD ["nginx", "-g", "daemon off;"]


#######################
# SSL : Secure Socket Layer : 네트워크 통신에서 사용되는 데이터 암호화 프로토콜
# - 서버와 클라이언트가 HTTP 프로토콜을 통해서 데이터를 주고 받을 때 암호화하여 전달하지 않으면 누군가 가로채어 내용을 확인을 하는 등 노출될 수 있다.
# HTTTPS 통신 : HTTP에서 SSL 프로토콜을 통해서 암호화한 데이터를 주고 받는 것
# TLS : transport Layer Sesurity : SSL 프로토콜에서 보안적으로 개선된 새로운 프로토콜
# - 현재는 SSL이 아닌 TLS를 통한 HTTPS 통신을 사용하지만 이 TLS를 SSL이라고 부르기도 한다.
# SSL 인증서 : CA기관에서 서버와 클라이언트간의 SSL기반 통신을 할 수 있게 서버측에 발급하는 하나의 파일
# 	- 발급받은 사람(조직) 
# 	- 발근한 인증기관
# 	- 발급 날짜
# 	- 만료 날짜
# 	- 공개키
# 	- 개인키
# : 브라우저는 웹서버와 통신시에 이러한 SSL통신을 위한 SSL인증서 데이터를 웹서버에 요청한다.
# 	- 브라우저와 웹서버가 통신하는 가장 첫 단계 : TLS HandShake
# 		- TLS 통신을 하는 양 당사자가 메세지를 교환하여 서로 통신에 사용될 암호화 알고리즘을 협의하는 과정


###logic

# - apt 업데이트 && 업그레이드
# - nginx, openssl 설치
# - ssl 설정
# - nginx config 파일 copy
# - nginx 실행




