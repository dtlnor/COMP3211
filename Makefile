CC:=gcc
#CFLAGS:=-Wall
exe:=bugAlgo
obj:=bugAlgo.c

all:$(obj)
	$(CC) -fprofile-arcs -ftest-coverage -o $(exe) $(obj)  
	./$(exe)
	gcov $(obj)
	make clean
	nano $(obj).gcov

.PHONY:clean
clean:
	rm -rf $(exe) $(exe).gcda $(exe).gcno

#gcc -fprofile-arcs -ftest-coverage -o bugAlgo2 bugAlgo2.c
#./bugAlgo2
#5 4 3 2 1
#gcov bugAlgo2.c
#pico bugAlgo2.c.gcov