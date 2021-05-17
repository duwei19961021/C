.PHONY:all
all:client server

client:udpClient.cc
	g++ -o $@ $^ -g
server:udpServer.cc
	g++ -o $@ $^ -g
.PHONY:clean

clean:
	rm -rf client server
