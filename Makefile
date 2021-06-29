PRGNAME = Ptr
OBJ = Ptr.o main.o
CFLAGS = -std=c99 -pedantic -Wall -W -g -O2 -pthread -ansi \
		-D _POSIX_C_SOURCE=200809L

all: Ptr

Ptr: $(OBJ)
	$(CC) -o $(PRGNAME) $(CFLAGS) $(OBJ)    -I/usr/include/tirpc 

main.o: main.c Ptr.h
	gcc -c  main.c  Ptr.h -I/usr/include/tirpc

Ptr.o: Ptr.c Ptr.h
	gcc -c  Ptr.c   -I/usr/include/tirpc


.PHONY: all clean

clean:
	rm -rf $(PRGNAME) *.o

dep:
	$(CC) -MM *.c

run:
	./Ptr
        
        
        
