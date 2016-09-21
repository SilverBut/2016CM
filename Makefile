CXX = gcc
CXXFLAGS = -g -Wall -O4 -mavx -lcrypto -std=c++11

PROGRAMS = problems generator
BLOCKS   = common.o twofish.o sha384.o flag_coder.o sha256.o

all : $(PROGRAMS)

problems: re300_problem.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
generator: re300_generator.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	$(RM) $(PROGRAMS)
	$(RM) *.o *.~
