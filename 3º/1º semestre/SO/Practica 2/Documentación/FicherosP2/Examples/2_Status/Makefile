CC = gcc
CFLAGS = -Wall -g

OBJECTS = status.o
PROG = status

all : $(PROG) 

$(PROG) : $(OBJECTS)
	gcc -g -o $(PROG) $(OBJECTS)
	
%.o : %.c 
	gcc -c $(CFLAGS) $<

clean :
	-rm $(OBJECTS) $(PROG) 	
