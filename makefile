output: main.c
	gcc main.c -I./include/ -L./libs -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o gin