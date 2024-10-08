#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
/* the list of integers */
int *list;
/* the threads will set these values */
double average;
int maximum;
int minimum;
void *calculate_average(void *param);
void *calculate_maximum(void *param);
void *calculate_minimum(void *param);

int main(int argc, char *argv[])
{
	int i;
	int num_of_args = argc-1;
	pthread_t tid_1;
    pthread_t tid_2;
    pthread_t tid_3;

    /* allocate memory to hold array of integers */
    list = malloc(sizeof(int)*num_of_args);

	for (i = 0; i < num_of_args; i++)
		//TODO: get data from command line and assign it to list

	/* create the threads */
	pthread_create(&tid_1, 0, calculate_average, &num_of_args);
	pthread_create(&tid_2, 0, calculate_maximum, &num_of_args);
	pthread_create(&tid_3, 0, calculate_minimum, &num_of_args);

	/* wait for the threads to exit */
	pthread_join(tid_1, NULL);
	pthread_join(tid_2, NULL);
	pthread_join(tid_3, NULL);

	printf("The average is %f\n", average);
	printf("The maximum is %d\n", maximum);
	printf("The minimum is %d\n", minimum);

	return 0;
}
