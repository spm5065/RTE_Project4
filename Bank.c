/*
 ============================================================================
 Name        : Bank.c
 Author      : Sergio Martins and Spencer Dennis
 Version     :
 Copyright   : 2017
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "stdhdr.h"
#include "teller.h"
#include "customer.h"
#include "queue.h"
#include "metrics.h"

struct BANK Bank = {0,0,0,0,0,0,0,0};

pthread_t tellerThreads[3];

int main(void) {
	time_t t;
	srand((unsigned) time(&t));
	initQueue();
	initTellers();

	puts("The Bank is opening for the day..."); /* prints !!!Hello World!!! */

	int turn = -1;

	fflush(stdout);

	//Start all the threads
	for(int threadNum = 0; threadNum < 3; threadNum++)
		if(pthread_create(&tellerThreads[threadNum], NULL, (void *) &runTeller, tellers[threadNum]))
			puts("Couldn't create a thread!");

	//Then ensure the threads are doing stuff
	while(doQueueAction());

	turn = -1;

	puts("The Bank has closed and finished the days business...");

	for(int i = 0; i < 3; i++)
		pthread_join(tellerThreads[i], NULL);

	calculate_metrics();

	destroyTellers();
	destroyQueue();

	return EXIT_SUCCESS;
}




