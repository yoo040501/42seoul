FROM debian:bullseye

RUN apt-get update && \
    apt-get -y install \
		php7.4 \
		php-fpm \
		php-cli \
		wget \
		curl \
		php-mysql \
		php-mbstring \
		php-xml \
		netcat-openbsd	\
		tini && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

EXPOSE 9000

COPY ./requirements/wordpress/tools/script.sh /

RUN chmod +x /script.sh
WORKDIR /var/www/html

ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["bash", "/script.sh"]