CC = g++
CFLAGS = -g -Wall -O2

TARGET = lucky_or_locky

default: $(TARGET)

$(TARGET): main.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp

clean:
	$(RM) $(TARGET)
	$(RM) *.o *.~
