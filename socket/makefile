### http://www.tenouk.com/Winsock/Winsock2example9.html

all: myserver.exe myclient.exe

myserver.exe: myserver.o
	g++ -o myserver.exe myserver.o -lws2_32

myserver.o: myserver.cpp
	g++ -c myserver.cpp -lws2_32

myclient.exe: myclient.o
	g++ -o myclient.exe myclient.o -lws2_32 -Wno-write-strings

myclient.o: myclient.cpp
	g++ -c myclient.cpp -lws2_32 -Wno-write-strings

clean:
	rm *.o
	rm *.exe
	


