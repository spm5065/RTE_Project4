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

void initQueue();
void destroyQueue();


#endif /* QUEUE_H_ */
