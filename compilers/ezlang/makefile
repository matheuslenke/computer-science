all: generate_flex compile_flex

generate_flex:
	flex -o ezlang.c ezlang.l

compile_flex:
	gcc -o ezlang.out ezlang.c

run:
	flex -o ezlang.c ezlang.l
	gcc -o ezlang.out ezlang.c
	./ezlang.out < teste.txt

clean:
	rm *.out
	rm *.c

