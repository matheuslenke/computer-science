CC=gcc
CFLAGS=-c -Wall -Ic:/fl
LDFLAGS= -Lc:/fl
LIBS= -lfl
SOURCES=lex.yy.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

.c.o:
    $(CC) $(CFLAGS) $< -o $@