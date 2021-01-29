/* Coursework - post office queueing system */ 
#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main(){
	/* setup random number generator */
	const gsl_rng_type	*T;
	gsl_rng			*r;
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc(T);
	gsl_rng_set(r, time(0));

	int i;
	for (i=0; i<10; i++){
		if(gsl_rng_uniform(r) > 0.5){ /* 50% chance of leaving the queue each timestep*/
			printf("Person %d decided to leave queue\n", i);
		}
	}

	printf("Queue at the postoffice for %f timesteps\n", gsl_rng_uniform(r)*i);

	return 0;
}


