t=$1
#CC=clang++
CC=g++

OPT=std=c++17
HEAP=268435456


all: $(t) exec

$(t) : $(t).cpp
	$(CC) -$(OPT) -o $(t) -g $(t).cpp

exec:
	./$(t)

clean:
	find . ! \( -name '*.cpp' -o -name 'Makefile' -o -name '.' \) | xargs rm -r
