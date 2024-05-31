CC = g++
SRC := $(shell find $(./) -name '*.cpp' -or -name '*.c' -or -name '*.s')
BIN = $(SRC:%.cpp=%)
 
all : ${BIN}
 
${BIN}:%:%.cpp
	${CC} $^ -o $@
 
clean:
	rm -rf ${BIN}
 
.PHONY: all clean