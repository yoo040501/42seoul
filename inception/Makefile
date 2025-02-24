all : up

up : 
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

down : 
	@docker-compose -f ./srcs/docker-compose.yml down

re :
	make up
	make down
	
status : 
	@docker ps