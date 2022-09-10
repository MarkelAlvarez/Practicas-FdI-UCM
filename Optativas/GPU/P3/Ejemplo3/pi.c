#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#ifdef _OPENACC
#include <openacc.h>
#endif


double get_time(){
	static struct timeval 	tv0;
	double time_, time;

	gettimeofday(&tv0,(struct timezone*)0);
	time_=(double)((tv0.tv_usec + (tv0.tv_sec)*1000000));
	time = time_/1000000;
	return(time);
}

int main(int argc, char **argv)
{
	int i, n;
	double t0, t1;
	double x, area, pi;

	if(argc > 1)
	{
		n = atoi(argv[1]);
	}
	else
	{
		printf("./exec n\n");
		return(-1);
	}

	t0 = get_time();
	area= 0.0;

	#pragma acc data copy(area)
    #pragma acc parallel loop reduction(+:area) private(x)
	for(i=1; i<n; i++)
	{
	    x = (i+0.5)/n;
		area += 4.0/(1.0 + x*x);
	}

	pi = area/n;
	t1 = get_time();
	printf("PI=%3.10f time=%lf (s)\n", pi, t1-t0);

	return 0;
}