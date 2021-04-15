all:select

select: main.o select_sort.o
	gcc -o main main.o select_sort.o

insert: main.o insert_sort.o
	gcc -o main main.o insert_sort.o

bubble: main.o bubble_sort.o
	gcc -o main main.o bubble_sort.o

shaker: main.o shaker_sort.o
	gcc -o main main.o shaker_sort.o

main.o: main.c item.h
	gcc -o main.o main.c -c

select_sort.o: select_sort.c item.h
	gcc select_sort.c -c -W -Wall

insert_sort.o: insert_sort.c item.h
	gcc insert_sort.c -c -W -Wall

bubble_sort.o: bubble_sort.c item.h
	gcc bubble_sort.c -c -W -Wall

shaker_sort.o: shaker_sort.c item.h
	gcc shaker_sort.c -c -W -Wall

run:
	./main
valgrind:
	valgrind --leak-check=full --tool=memcheck --track-origins=yes ./main