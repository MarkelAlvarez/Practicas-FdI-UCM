CFLAGS  = -Wall -g -pthread
SRC1 = partial_sum1.c
SRC2 = partial_sum2.c
PROG1   = partial_sum1
PROG2   = partial_sum2

all :
	gcc $(CFLAGS) -o $(PROG1) $(SRC1)
	gcc $(CFLAGS) -o $(PROG2) $(SRC2)

clean :
	-rm -f $(PROG1) $(PROG2)
