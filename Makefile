CC=gcc
CFLAGS=-O3
LIBS=-lcurl -lcjson
OUT=dred.o net.o parse.o

all: dred

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(LIBS)

dred: $(OUT)
	$(CC) $(CFLAGS) -g -o dred $(OUT) $(LIBS)


.PHONY: clean
clean:
	rm -f *.o dred
