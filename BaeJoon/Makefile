t=$1
CC=clang++
OPT=std=c++17


all: $(t) exec

$(t) : $(t).cpp
	$(CC) -$(OPT) -o $(t) -g $(t).cpp

exec:
	./$(t)

clean:
	find . ! \( -name '*.cpp' -o -name 'Makefile' -o -name '.' \) | xargs rm -r
