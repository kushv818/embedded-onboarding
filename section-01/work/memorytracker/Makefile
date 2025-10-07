CC = gcc
CFLAGS = -I../inc -g -Wall
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
EXEC = memory_tracker

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
