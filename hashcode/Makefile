CC=g++
CFLAGS= -std=c++14 -Wall -Wextra -Wpedantic -Wno-unused-result -DLOCAL
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(SRC)
	$(CC) -O2 $(CFLAGS) $^

debug: $(SRC)
	$(CC) -O2 -std=c++14 $^

clean:
	rm -f *.o *.out
