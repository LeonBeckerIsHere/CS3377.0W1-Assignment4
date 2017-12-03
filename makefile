
Assignment04: a4Server1 a4Client1 a4Client2 a4Client3 book1 book2 book.db

a4Server1: a4Server1.c
	gcc a4Server1.c -o a4Server1 -lpthread -lsqlite3

a4Client1: a4Client1.c
	gcc a4Client1.c -o a4Client1

a4Client2: a4Client2.c
	gcc a4Client2.c -o a4Client2
	
a4Client3: a4Client3.c
	gcc a4Client3.c -o a4Client3

book1: book1.cpp
	g++ -g -Wall -std=c++11 -DDEBUG book1.cpp -o book1 -lsqlite3

book2: book2.cpp
	g++ -g -Wall -std=c++11 -DDEBUG book2.cpp -o book2 -lsqlite3

book.db:
	./book1
	./book2

clean:
	rm -rf a4Server1 a4Client1 a4Client2 a4Client3 book1 book2 book.db

runserver:
	./a4Server1 10296

runc1:
	./a4Client1 127.0.0.1 10296

runc2:
	./a4Client2 127.0.0.1 10296

runc3:
	./a4Client3 127.0.0.1 10296
