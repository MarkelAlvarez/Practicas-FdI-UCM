CC = gcc
CFLAGS = -Wall -g

OBJECTS = distr.o
PROG = distribution

all : $(PROG)

$(PROG) : $(OBJECTS)
	gcc -g -o $(PROG) $(OBJECTS)

%.o : %.c
	gcc -c $(CFLAGS) $<

clean :
	-rm $(OBJECTS) $(PROG)
