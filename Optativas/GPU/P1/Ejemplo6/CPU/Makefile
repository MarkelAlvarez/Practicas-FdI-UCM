CC			= gcc 
EXE			= transpose 
SOURCES		= transpose.c
OBJS    	= $(SOURCES:.c=.o)
CFLAGS		= -O3 -fopenmp 
LIBS 		= -lm 
SOURCEDIR 	= .

$(EXE) :$(OBJS) 
	$(CC) $(CFLAGS)  -o $@ $? $(LIBS)

$(SOURCEDIR)/%.o : $(SOURCEDIR)/%.c 
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(EXE)