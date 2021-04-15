all: prog

prog: tAluno.o
	gcc -o prog tAluno.o main.c

tAluno.o: tAluno.h
	gcc -c tAluno.h tAluno.c

run: main
	./main

clean:
	@rm main *.o