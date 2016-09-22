#CXX = g++
#CXXFLAGS = -g -Wall -O4 -mavx -lcrypto -std=c++11
CXX = clang++
CXXFLAGS = -g -Wall -O3 -mavx -std=c++11 
# -lcrypto 

PROGRAMS = problem generator
#PROGRAMS = generator
ALGOS    = sha256.o sha384.o twofish.o
BTC_OBJS = btc_simple_block.o
WRAPERS  = flag_coder.o $(BTC_OBJS)
BLOCKS   = common.o $(ALGOS) $(WRAPERS)

all : clean $(PROGRAMS)

problem: re300_problem.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -D IS_PROBLEM $^ -o $@
	
generator: re300_generator.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -D IS_SOLVER $^ -o $@ 

re300_problem.o: re300_problem.cpp generator
	./generator
	$(CXX) $(CXXFLAGS) -D IS_PROBLEM -c re300_problem.cpp -o re300_problem.o

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $^ -o $@ 

clean:
	$(RM) $(PROGRAMS)
	$(RM) *.o *.~
	$(RM) flag.h
