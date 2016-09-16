CC = g++
CFLAGS = -g -Wall -O2

TARGET = lucky_or_locky
SOLVER = lucky_melon

COMMON = common

default: $(TARGET) $(SOLVER)

$(TARGET): twofish.o problem.cpp  $(COMMON).cpp $(COMMON).h
	$(CC) $(CFLAGS) -o $(TARGET) problem.cpp $(COMMON).cpp twofish.o

$(SOLVER): twofish.o solver.cpp $(COMMON).h $(COMMON).cpp
	$(CC) $(CFLAGS) -o $(SOLVER) solver.cpp $(COMMON).cpp twofish.o

twofish.o: twofish.cpp twofish.h
	$(CC) $(CFLAGS) -o twofish.o -c twofish.cpp

clean:
	$(RM) $(TARGET) $(SOLVER)
	$(RM) *.o *.~
