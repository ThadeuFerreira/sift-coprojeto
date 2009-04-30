
# Include flag -g for debug.
# Include flags -g -pg for profiling.
all:
	g++ -c ./opencv/*.cpp
	gcc -c -I./opencv/ *.c
	gcc *.o -o sift

clean:
	rm -rf *.o *.o *~ '#*' '*#' sift sift.exe
