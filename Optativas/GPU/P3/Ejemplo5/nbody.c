#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>
#include <sys/resource.h>

double get_time()
{
	static struct timeval 	tv0;
	double time_, time;

	gettimeofday(&tv0,(struct timezone*)0);
	time_=(double)((tv0.tv_usec + (tv0.tv_sec)*1000000));
	time = time_/1000000;
	return(time);
}

typedef struct { float m, x, y, z, vx, vy, vz; } body;

void randomizeBodies(body *data, int n)
{
	for (int i = 0; i < n; i++)\
	{
		data[i].m  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;

		data[i].x  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data[i].y  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data[i].z  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;

		data[i].vx = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data[i].vy = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data[i].vz = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
	}
}

/*
void bodyForce(body *p, float dt, int n)
{
	for (int i = 0; i < n; i++)
	{ 
		float Fx = 0.0f; float Fy = 0.0f; float Fz = 0.0f;

		for (int j = 0; j < n; j++)
		{
			if (i!=j)
			{
				float dx = p[j].x - p[i].x;
				float dy = p[j].y - p[i].y;
				float dz = p[j].z - p[i].z;
				float distSqr = dx*dx + dy*dy + dz*dz;
				float invDist = 1.0f / sqrtf(distSqr);
				float invDist3 = invDist * invDist * invDist;

				float G = 6.674e-11;
				float g_masses = G * p[j].m * p[i].m;

				Fx += g_masses * dx * invDist3; 
				Fy += g_masses * dy * invDist3; 
				Fz += g_masses * dz * invDist3;
			}
		}

		p[i].vx += dt*Fx/p[i].m;
		p[i].vy += dt*Fy/p[i].m;
		p[i].vz += dt*Fz/p[i].m;
	}
}

void integrate(body *p, float dt, int n)
{
	for (int i = 0 ; i < n; i++)
	{
		p[i].x += p[i].vx*dt;
		p[i].y += p[i].vy*dt;
		p[i].z += p[i].vz*dt;
	}
}
*/

/*
 * Como no sabia como crear un pragma para decirle a la GPU
 * que podia juntar los dos bucles de funciones distintas
 * he decidido unificarlo todo y hacerlo de esta forma.
 */
void bodyForceAndIntegrate(body *p, float dt, int n)
{
    #pragma acc data present(p[:n])
    #pragma acc parallel loop
	for (int i = 0; i < n; i++)
	{ 
		float Fx = 0.0f;
		float Fy = 0.0f;
		float Fz = 0.0f;

        #pragma acc loop gang reduction(+:Fx) reduction(+:Fy) reduction(+:Fz)
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				float dx = p[j].x - p[i].x;
				float dy = p[j].y - p[i].y;
				float dz = p[j].z - p[i].z;
				float distSqr = dx*dx + dy*dy + dz*dz;
				float invDist = 1.0f / sqrtf(distSqr);
				float invDist3 = invDist * invDist * invDist;

				float G = 6.674e-11;
				float g_masses = G * p[j].m * p[i].m;

				Fx += g_masses * dx * invDist3; 
				Fy += g_masses * dy * invDist3; 
				Fz += g_masses * dz * invDist3;
			}
		}

		p[i].vx += dt*Fx/p[i].m;
		p[i].vy += dt*Fy/p[i].m;
		p[i].vz += dt*Fz/p[i].m;

		p[i].x += p[i].vx*dt;
		p[i].y += p[i].vy*dt;
		p[i].z += p[i].vz*dt;
	}
}

int main(const int argc, const char** argv)
{
	int nBodies = 1000;

	if (argc > 1) nBodies = atoi(argv[1]);

	const float dt = 0.01f; // time step
	const int nIters = 100;  // simulation iterations

	body *p = (body*)malloc(nBodies*sizeof(body));

	randomizeBodies(p, nBodies); // Init pos / vel data

	double t0 = get_time();

	#pragma acc data copy(p[:nBodies])
	{
		for (int iter = 1; iter <= nIters; iter++)
		{
			/*
			bodyForce(p, dt, nBodies); // compute interbody forces
			integrate(p, dt, nBodies); // integrate position
			*/
			bodyForceAndIntegrate(p, dt, nBodies); // compute interbody forces and integrate
		}
	}
	
	double totalTime = get_time()-t0; 
	printf("%d Bodies with %d iterations: %0.3f Millions Interactions/second\n", nBodies, nIters, 1e-6 * nBodies * nBodies / totalTime);

	free(p);
}
