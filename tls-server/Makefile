all:
	gcc -g -O0 server.c -o ssl_server -lssl -lcrypto

genpem:
	openssl req -newkey rsa:2048 -nodes -keyout key.pem -x509 -days 365 -out cert.pem
