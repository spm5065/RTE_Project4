/*
 * queue.h
 *
 *  Created on: Apr 3, 2017
 *      Author: spm5065
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "stdhdr.h"
#include "customer.h"

#define QUEUE_SIZE 100
extern Customer 		*queue[QUEUE_SIZE];
extern int 		 	 	 numInQueue;
extern pthread_mutex_t 	 queueLock;
extern sem_t			 turnSemaphore;

int tNextCust = 0;

void initQueue();
void destroyQueue();

Customer 	*popQueue();
void	  	 pushQueue( Customer * );
int			 getQueueSize();


#endif /* QUEUE_H_ */
