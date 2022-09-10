CXX = dpcpp

CXXFLAGS=-O3 -I.

LIBS =


%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

all: gen_md5 crack_md5

gen_md5: md5.o gen_md5.o
	$(CXX) $^ $(CXXFLAGS) $(LIBS) -o $@

crack_md5: md5.o brute_force.o
	$(CXX) $^ $(CXXFLAGS) $(LIBS) -o $@

clean:
	rm -f gen_md5 crack_md5 *.o
