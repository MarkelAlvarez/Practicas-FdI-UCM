CC = gcc
CFLAGS = -Wall -g

OBJECTS = copy.o
PROG = copy

all : $(PROG) 

$(PROG) : $(OBJECTS)
	gcc -g -o $(PROG) $(OBJECTS)
	
%.o : %.c 
	gcc -c $(CFLAGS) $<

clean :
	-rm $(OBJECTS) $(PROG) 
