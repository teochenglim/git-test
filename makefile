all: 1.exe 2.exe

1.exe: 1.o
	g++ -o 1 1.o

1.o: 1.cpp
	g++ -c 1.cpp


2.exe: 2.o
	gcc -o 2 2.o

2.o: 2.c
	g++ -c 2.c

clean:
	rm *.o
	rm *.exe