/*
 * queue.c
 *
 *  Created on: Apr 3, 2017
 *      Author: spm5065
 */
#include <time.h>
#include "queue.h"

Customer 			*queue[QUEUE_SIZE];
int 		 	 	 numInQueue;
pthread_mutex_t 	 queueLock;
sem_t				 turnSemaphore;
int 				 tNextCust = 0;

//Initialize the queue
void initQueue() {
	memset( queue, 0, sizeof(Customer *) * QUEUE_SIZE );

	if (pthread_mutex_init( &queueLock, NULL)) {
		puts("Failed to initialize the mutex.");
	}

	if ( sem_init(&turnSemaphore, 0, 3360) ){
		puts("Failed to initialize the semaphore.");
	}

	tNextCust = RandomNextCustomerTime();

}

//Cleanup queue
void destroyQueue(){
	for(int i = 0; i < QUEUE_SIZE; i++){
		if( queue[i] ) free(queue[i]);
		queue[i] = NULL;
	}

	pthread_mutex_destroy( &queueLock );
	sem_destroy(&turnSemaphore);
}

void UpdateQueueMetrics(){
	//Ensure we store the max number of people in the queue
	if(numInQueue > Bank.maxNumInQueue){
		Bank.maxNumInQueue = numInQueue;
	}

	//Increment each persons time in the queue
	for(int i = 0; i < numInQueue; i++){
		queue[i]->timeInQueue++;
	}
}

int doQueueAction(){

	int turn = -1;	//Value for turn
	int rc = 1;		//Return Code

	//Get the turn, and check if its my turn
	if( (sem_getvalue( &turnSemaphore, &turn ) != -1) && (turn % 4 == 0) ){

		//Are we open
		if(turn > 0){
			if (--tNextCust <= 0) {
				Customer *newCust = (Customer *) malloc(sizeof(Customer));

				pushQueue(newCust);
				tNextCust = RandomNextCustomerTime();
			}

		} else { //Not open
			if(numInQueue == 0) rc = 0;
		}

		UpdateQueueMetrics();
		struct timespec t;
		t.tv_sec = 0;
		t.tv_nsec = 50000000;
		nanosleep(&t, NULL);

		if (turn != 0) sem_wait(&turnSemaphore);
	}

	struct timespec t;
	t.tv_sec = 0;
	t.tv_nsec = 5000;
	nanosleep(&t, NULL);

	return rc;
}

void runQueue(){
	int i = 0;
	while (doQueueAction() && i < 100000){i++;}//doAction endlessly
}
//Thread-safe queue grab
int getQueueSize(){
	pthread_mutex_lock(&queueLock);
	int value = numInQueue;
	pthread_mutex_unlock(&queueLock);
	return value;
}

//Add customer to the queue
void pushQueue(Customer *cust){
	pthread_mutex_lock(&queueLock);
	queue[numInQueue++] = cust;
	if(Bank.maxNumInQueue < numInQueue) Bank.maxNumInQueue = numInQueue;
	pthread_mutex_unlock(&queueLock);
}

//Get a customer from the queue
Customer *popQueue(){
	//Get a lock on the mutex
	pthread_mutex_lock(&queueLock);

	Customer *returnCust = NULL;
	if( numInQueue > 0) {

		//Get customer and dec num in queue
		returnCust = queue[0];
		numInQueue--;

		//shift people forward in queue and remove dupe
		memcpy(&queue[0], &queue[1], sizeof(Customer *) * (QUEUE_SIZE - 1) );
		queue[QUEUE_SIZE - 1] = 0;
	}

	//Unlock the mutex
	pthread_mutex_unlock(&queueLock);

	return returnCust;
}


