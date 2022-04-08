OS = LINUX

CC = gcc
CFLAGS = -I./include/ -L./libs/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
NAME = gin

ifeq ($(OS), WINDOWS)
CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -s -O1 -I./include/ -L./libs/ -Wl,--subsystem,windows -lraylibwin -lopengl32 -lgdi32 -lwinmm -static -lpthread -DPLATFORM_DESKTOP
NAME = gin.exe
endif
OBJ = main.o inputDebugger.o

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $^ $(CFLAGS)

clean:
	rm *.o


# windows: mingw

# output: main.o inputDebugger.o
# 	gcc main.o inputDebugger.o -I./include/ -L./libs -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o gin

# mingw: main.c inputDebugger.c
# 	x86_64-w64-mingw32-gcc main.c inputDebugger.c -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -s -O1 -I./include/ -L./libs/ -Wl,--subsystem,windows -lraylibwin -lopengl32 -lgdi32 -lwinmm -static -lpthread -DPLATFORM_DESKTOP

# main: main.c
# 	gcc -c main.c

# inputDebugger: inputDebugger.c
# 	gcc -c inputDebugger

# clean:
# 	rm *.o