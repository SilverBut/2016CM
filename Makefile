CXX = g++
CXXFLAGS = -g -Wall -O4 -mavx -lcrypto

PROGRAMS = locky_or_lucky lucky_melon
BLOCKS   = twofish.o common.o chain.o sha384.o flag_coder.o

all : $(PROGRAMS)

locky_or_lucky: problem.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
lucky_melon: solver.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	$(RM) $(PROGRAMS)
	$(RM) *.o *.~
