#CXX = g++
#CXXFLAGS = -g -Wall -O4 -mavx -lcrypto -std=c++11
CXX = clang++
CXXFLAGS = -g -Wall -O3 -mavx -std=c++11 
# -lcrypto 

#PROGRAMS = problems generator
PROGRAMS = generator
ALGOS    = sha256.o sha384.o twofish.o
BTC_OBJS = btc_simple_block.o
WRAPERS  = flag_coder.o $(BTC_OBJS)
BLOCKS   = common.o $(ALGOS) $(WRAPERS)

all : clean $(PROGRAMS)

problems: re300_problem.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
generator: re300_generator.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	$(RM) $(PROGRAMS)
	$(RM) *.o *.~
