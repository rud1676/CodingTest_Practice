t=$1
CC=g++
OPT=std=c++11


all: $(t) exec

$(t) : $(t).cpp
	$(CC) -$(OPT) -o $(t) $(t).cpp

exec:
	./$(t)

clean:
	rm -rf `ls | grep -v Makefile | grep -v *.cpp`
