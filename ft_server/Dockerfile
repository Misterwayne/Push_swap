FROM debian:buster


LABEL Malick Wane <mwane@student.42.fr>
COPY nginx-conf /root/
COPY hello.sh ./
RUN mkdir -p /var/www/html
COPY test.html /var/www/html/
RUN apt-get upgrade -y && apt-get -y update && apt-get install -y wget nginx
CMD bash hello.sh