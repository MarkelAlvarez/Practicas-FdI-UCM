CC = nvcc 

EXE   = transpose 

SOURCES    = transpose.cu


OBJS    = $(SOURCES:.cu=.o)

CFLAGS     = -O3  

LIBS = -lm 

SOURCEDIR = .

$(EXE) :$(OBJS) 
	$(CC) $(CFLAGS)  -o $@ $? $(LIBS)

$(SOURCEDIR)/%.o : $(SOURCEDIR)/%.cu
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f $(OBJS) $(EXE)
