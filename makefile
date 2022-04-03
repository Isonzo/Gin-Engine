all: output clean

output: main.o inputDebugger.o
	gcc main.o inputDebugger.o -I./include/ -L./libs -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o gin

main: main.c
	gcc -c main.c

inputDebugger: inputDebugger.c
	gcc -c inputDebugger

clean:
	rm *.o