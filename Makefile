CC = g++
SRC = $(wildcard *.cpp)
BIN = $(SRC:%.cpp=%)
 
all : ${BIN}
 
${BIN}:%:%.cpp
	${CC} $^ -o $@
 
clean:
	rm -rf ${BIN}
 
.PHONY: all clean