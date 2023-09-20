TARGET = array_list
CC=gcc
CFLAGS =-I. -Wall -Wextra
HEADERS = array_list.h dlinked_list.h node.h
OBJ = main.o array_list.o node.o dlinked_list.o 

%.o : %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm ./$(TARGET) *.o 