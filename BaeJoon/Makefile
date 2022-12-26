t=$1
CC=g++
OPT=std=c++11


all: $(t) exec

$(t) : $(t).cpp
	$(CC) -$(OPT) -o $(t) $(t).cpp

exec:
	./$(t)

clean:
	find . ! \( -name '*.cpp' -o -name 'Makefile' -o -name '.' \) | xargs rm -r
