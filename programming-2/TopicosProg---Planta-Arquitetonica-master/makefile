### MAKEFILE ###
CC=gcc
CFLAGS=  -lm
DEPS = ponto.h circulo.h triangulo.h retangulo.h comodo.h planta.h
OBJ = ponto.o circulo.o triangulo.o retangulo.o comodo.o planta.o cliente.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


testando: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o




# prog.out: ponto.o circulo.o retangulo.o
# 	gcc ponto.o circulo.o retangulo.o -o prog.out -lm

# ponto.o: ponto.c
# 	gcc -c ponto.c -lm

# circulo.o: circulo.c
# 	gcc -c circulo.c -lm

# retangulo.o: retangulo.c
# 	gcc -c retangulo.c -lm