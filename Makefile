#CXX = g++
#CXXFLAGS = -g -Wall -O4 -mavx -lcrypto -std=c++11
#CXX = clang++
#CXXFLAGS = -g -Wall -O3 -mavx -std=c++11
CXX = clang++
CXXFLAGS = -Wall -O3 -std=c++11
#CXX = g++
#CXXFLAGS = -Wall -O4 -s -std=c++11
# -lcrypto 

PROGRAMS = problem generator
#PROGRAMS = generator
ALGOS    = sha256.o sha384.o twofish.o
BTC_OBJS = btc_simple_block.o
WRAPERS  = flag_coder.o $(BTC_OBJS)
BLOCKS   = common.o $(ALGOS) $(WRAPERS)

all : clean $(PROGRAMS)

test : clean problem
	./problem

problem: re300_problem.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -D IS_PROBLEM $^ -o $@
#	strip problem
	
generator: re300_generator.o $(BLOCKS)
	$(CXX) $(CXXFLAGS) -D IS_SOLVER $^ -o $@ 

re300_problem.o: re300_problem.cpp generator
	./generator
	$(CXX) $(CXXFLAGS) -D IS_PROBLEM -c re300_problem.cpp -o re300_problem.o

common.o : common.cpp
	$(CXX) $(CXXFLAGS) -mavx -c $^ -o $@

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $^ -o $@ 

clean:
	$(RM) $(PROGRAMS)
	$(RM) *.o *.~
	$(RM) flag.h magic_file newblocks
	$(RM) *.zip
	$(RM) problem_*
	$(RM) *.map 

pack: clean get_old_file all get_mod_file
	strip -w -N "*BitChain*" -N "*minin*" -N "xor*" -N "*swap*" -N "*hex*" -N "*256*" -N "*crypt*" -N "*prev_h*" -N "*fill_k*" problem -o problem_partially_stripped
	zip re399_partially_stripped.zip problem_partially_stripped magic_file
	strip problem -o problem_fully_stripped
	zip re399_fully_stripped.zip problem_fully_stripped magic_file
	readelf -s problem_partially_stripped > re399_partial.map
	readelf -s problem > re399_full.map
	zip ../re399.zip re399_partially_stripped.zip re399_fully_stripped.zip re399_partial.map re399_full.map README.md

get_old_file:
	cd ./fetch_block_chain ; python abstracter.py | tail -n 3
	cp ./fetch_block_chain/newblocks ./

get_mod_file:
	cd ./fetch_block_chain ; python abstract_new.py | tail -n 3
	cp ./fetch_block_chain/magic_file ./
