all: helloworld.c
	clang -g helloworld.c -fopenmp -o helloworld

