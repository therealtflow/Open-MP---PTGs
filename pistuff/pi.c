#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cblas.h>
#include <time.h>

static long num_steps = 100000;
double step;

double get_time_diff(struct timespec start, struct timespec end)
{
return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) /
1000000000.0;
}

int main ()
{
	struct timespec start_full, end_full;
    clock_gettime(CLOCK_MONOTONIC, &start_full);	
    int i; 
    double x; 
    double pi; 
    double sum = 0.0;
    step = 1.0/(double) num_steps;
#pragma omp parallel for reduction(+:sum)
    for (i=0; i < num_steps; i++)
    {
        x = (i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }
    pi = step * sum;

    printf("pi: %lf\n", pi);
clock_gettime(CLOCK_MONOTONIC, &end_full);
printf("%.9f\n", get_time_diff(start_full, end_full));
    return 0;
}
