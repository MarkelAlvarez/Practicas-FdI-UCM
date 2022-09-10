CC=gcc

CFLAGS=-O3 -lm -lrt 

PGCC=pgcc -Minfo -fast -acc -ta=nvidia -tp=nehalem

NAME=image

default: host gpu

host:
	$(CC) $(CFLAGS) $(NAME).c -o $(NAME).host.exe

gpu: pgi


pgi:
	$(PGCC) $(NAME).c -o $(NAME).pgi.exe

clean: 
	rm -f _ *.exe
