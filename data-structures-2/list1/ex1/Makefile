all:main

main: main.o primeNumberInt.o primeNumberBool.o primeNumberBit.o primeNumber.o bitmap.o
	gcc -o main main.o primeNumber.o primeNumberInt.o primeNumberBool.o primeNumberBit.o bitmap.o

main.o: main.c primeNumber.h primeNumberBit.h primeNumberInt.h primeNumberBool.h bitmap.h
	gcc -o main.o main.c -c

bitmap.o: bitmap.c bitmap.h
	gcc bitmap.c -c -W -Wall

primeNumberInt.o: primeNumberInt.c primeNumberInt.h
	gcc primeNumberInt.c -c -W -Wall

primeNumberBool.o: primeNumberBool.c primeNumberBool.h
	gcc primeNumberBool.c -c -W -Wall

primeNumberBit.o: primeNumberBit.c primeNumberBit.h
	gcc primeNumberBit.c -c -W -Wall

primeNumber.o: primeNumber.c primeNumber.h
	gcc primeNumber.c -c -W -Wall

run:
	./main
valgrind:
	valgrind --leak-check=full --tool=memcheck --track-origins=yes ./main