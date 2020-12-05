mCFLAGS=-std=c99 -Wall
CC=gcc

random_sequence: struct.o main.o
	$(CC) $(CFLAGS) struct.o main.o -o final_project

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sequence.o: struct.h struct.c
	$(CC) $(CFLAGS) -c struct.c

clean:
	rm -f final_project *.o
