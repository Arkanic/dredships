CC=gcc
CFLAGS=-O3 -lcurl
OUT=dred.o net.o

all: dred

%.o: %.c
	$(CC) $(CFLAGS) -c $<

dred: $(OUT)
	$(CC) $(CFLAGS) -g -o dred $(OUT)


.PHONY: clean
clean:
	rm -f *.o dred
