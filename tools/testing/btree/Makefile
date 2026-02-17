CC = gcc
CFLAGS = -Wall -O2 -g -I. -I../../../include

TARGET = btree_test

all: $(TARGET)

btree_test: btree_test.c btree.c
	$(CC) $(CFLAGS) -o $@ btree_test.c btree.c

btree.c:
	ln -sf ../../../lib/btree.c btree.c

clean:
	rm -f $(TARGET) btree.c
