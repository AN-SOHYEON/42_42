


CREATE DATABASE wordpress_db

CREATE USER 'san'@'%' IDENTIFIED BY 'password';

GRANT ALL ON wordpress_db.* TO 'san'@'%';

FLUSH PRIVILEGES;


--  Docker compose로 mysql/mariadb 세팅하기 https://int-i.github.io/sql/2020-12-31/mysql-docker-compose/ 
