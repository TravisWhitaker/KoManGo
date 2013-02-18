CC = clang
#If Linux, use libncursesw, else use libncurses and assume platform UTF-8 support:
UNAME := $(shell uname)
ifeq ($(UNAME),Linux)
CFLAGS = -lncursesw
endif
ifeq ($(UNAME),Darwin)
CFLAGS = -lncurses
endif

INCLUDE = -I./include
SOURCE = $(wildcard src/*.c)
OUT = -o
EXECUTABLE = komango

all:
	@echo "Your platform is $(UNAME)"
	$(CC) $(CFLAGS) $(INCLUDE) $(OUT) $(EXECUTABLE) $(SOURCE)

install:
	cp $(EXECUTABLE) /usr/bin/

clean:
	rm $(EXECUTABLE)
