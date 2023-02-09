t=$1
#CC=clang++
CC=g++

OPT=std=c++14


all: $(t) exec

$(t) : $(t).cpp
	$(CC) -$(OPT) -Wall -o $(t) -g $(t).cpp

exec:
	./$(t)

clean:
	find . ! \( -name '*.cpp' -o -name 'Makefile' -o -name '.' \) | xargs rm -r

temp: 
	$(CC) -$(OPT) -o temp -g temp.cpp
	./temp
