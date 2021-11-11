# the compiler: gcc for C program, define as g++ for C++
CC = gcc
CXX = g++
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
LINKING = -lglut -lGL -lGLU
TARGET = *

all:
	$(CXX) $(CFLAGS) -o out $(TARGET).cpp $(LINKING)
	./out

quadrado:
	$(CXX) $(CFLAGS) -o out quadrado.cpp $(LINKING)
	./out

spline:
	$(CXX) $(CFLAGS) -o out spline.cpp $(LINKING)
	./out

clean:
	$(RM) $(TARGET)