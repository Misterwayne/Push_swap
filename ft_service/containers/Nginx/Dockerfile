FROM alpine:latest

RUN apk update && apk add nginx \
&& apk add --upgrade bash \
&& apk add openssl && mkdir -p var/run/nginx \
&& apk add openssl openssh


RUN adduser -D -g 'nginx_user' nginx_user \
&& mkdir /nginx_user && chown -R nginx_user:nginx_user /var/lib/nginx \
&& chown -R nginx_user:nginx_user /nginx_user

RUN rm /etc/nginx/nginx.conf
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./lunch.sh /lunch.sh
COPY ./index.html nginx_user/
RUN chmod +x /lunch.sh
EXPOSE 80 80
CMD ./lunch.sh