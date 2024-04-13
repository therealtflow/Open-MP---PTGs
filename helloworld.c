#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
#pragma omp parallel
	{
	printf("Hello World!");
	}
}