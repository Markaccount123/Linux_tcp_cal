FLAG=-std=c++11

.PHONY:all
all:server client

server:Server.cc
	g++ -o $@ $^ $(FLAG) 
client:Client.cc 
	g++ -o $@ $^ $(FLAG) 

.PHONY:clean
clean:
	rm -f  server client
