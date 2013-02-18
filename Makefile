CC = clang
CFLAGS = -lncursesw
SOURCE = $(wildcard src/*.c)
INCLUDE = -I./include
OUT = -o
EXECUTABLE = komango

all:
	$(CC) $(CFLAGS) $(INCLUDE) $(OUT) $(EXECUTABLE) $(SOURCE)

install:
	cp $(EXECUTABLE) /usr/bin/

clean:
	rm $(EXECUTABLE)
