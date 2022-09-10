


CC=gcc

CFLAGS=-O3

PGCC=pgcc -Minfo -fast -acc -ta=nvidia -tp=nehalem

LIB=-lm

NAME=nbody

default: host gpu

host:
	$(CC) $(CFLAGS) $(NAME).c -o $(NAME).host.exe $(LIB)

gpu: pgi


pgi:
	$(PGCC) $(NAME).c -o $(NAME).pgi.exe $(LIB)

clean: 
	rm -f _ *.exe
