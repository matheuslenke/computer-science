
all: bison gcc
	@echo "Done."

bison: parser.y
	bison parser.y --defines=parser.h -o parser.c

gcc:  parser.c
	gcc -Wall  parser.c -ly

clean:
	@rm -f *.o *.output  parser.h parser.c a.out parser.tab.c
