all:main

main: main.o josefo.o lista.o
	gcc -o main main.o lista.o josefo.o

main.o: main.c josefo.h lista.h
	gcc -o main.o main.c -c

lista.o: lista.c lista.h
	gcc lista.c -c -W -Wall

josefo.o: josefo.c josefo.h
	gcc josefo.c -c -W -Wall

run:
	./main
valgrind:
	valgrind --leak-check=full --tool=memcheck --track-origins=yes ./main