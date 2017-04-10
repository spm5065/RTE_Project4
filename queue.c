/*
 * queue.c
 *
 *  Created on: Apr 3, 2017
 *      Author: spm5065
 */
#include "queue.h"

Customer 			*queue[QUEUE_SIZE];
int 		 	 	 numInQueue;
pthread_mutex_t 	 queueLock;
sem_t				 turnSemaphore;

void initQueue(){
	memset( queue, 0, sizeof(Customer *) * QUEUE_SIZE );

	if (pthread_mutex_init( &queueLock, NULL)) {
		puts("Failed to initialize the mutex.");
	}

	if ( sem_init(&turnSemaphore, 0, 0) ){
		puts("Failed to initalize the semaphore.");
	}
}

void destroyQueue(){
	for(int i = 0; i < QUEUE_SIZE; i++){
		if( queue[i] ) free(queue[i]);
		queue[i] = NULL;
	}

	pthread_mutex_destroy( &queueLock );
	sem_destroy(&turnSemaphore);
}

int doAction(){
	int turn = -1;

	//Get the turn, and check if its my turn
	if( sem_getValue( &turnSemaphore, &turn ) != -1 && (turn % 4 == 0) ){
		//Are we open
		if( turn < 3360){
			if (--tNextCust == 0){
				Customer *newCust = (Customer *) malloc(sizeof(Customer));

				pushQueue(newCust);
			}
			return 1;
		} else { //Not open

		}
	}
}

int getQueueSize(){
	pthread_mutex_lock(&queueLock);
	int value = numInQueue;
	pthread_mutex_unlock(&queueLock);
	return value;
}
