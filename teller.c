/*
 * teller.c
 *
 *  Created on: Apr 3, 2017
 *      Author: spm5065
 */

#include "teller.h"
#include "queue.h"

Teller *tellers[3];

void initTellers(){
	for( int i = 0; i < 3; i++){
		tellers[i] = (Teller *) malloc(sizeof(Teller));
		Teller *t = tellers[i];
		t->maxBreak 		= 0;
		t->minBreak		= 0;
		t->totalBreak	= 0;
		t->numBreaks	= 0;
		t->downTime		= 0;
		t->customerWith	= NULL;
		t->tellerNum 	= i+1;
		t->timeRem		= 0;
	}
}

void destroyTellers(){
	for( int i = 0; i < 3; i++){
		free(tellers[i]);
	}
}

int doTellerAction(Teller *t){
	int turn = -1;	//Value for turn
	int rc = 1;		//Return Code

	//Get the turn, and check if its my turn
	if( sem_getvalue( &turnSemaphore, &turn ) != -1 && (turn % 4 == t->tellerNum) ){
		sem_wait(&turnSemaphore);

		//No Customer
		if(customerWith == NULL){

			//If people in queue, get customer
			if(getQueueSize()){
				t->customerWith = popQueue();
				t->timeRem = RandomTransactionTime();
				t->customerWith->timeWithTeller = t->timeRem;

			//else check if we need to continue
			} else {
				if(t <= 3360)
					t->downTime++;
				else
					rc = 0;
			}
		} else {
			if(--t->timeRem == 0){
				//FinishTransaction
				if(t->customerWith->timeWithTeller > Bank.maxTimeInTransaction)
					Bank.maxTimeInTransaction = t->customerWith->timeWithTeller;

				if(t->customerWith->timeInQueue > Bank.maxTimeInQueueCust)
					Bank.maxTimeInQueue = t->customerWith->timeInQueue;

				Bank.totalTimeWithTellers += t->customerWith->timeWithTeller;
				Bank.customersServiced++;
				Bank.totalTimeInQueue += t->customerWith->timeInQueue;

			} else {

			}
		}

		sem_post(&turnSemaphore);
	}

	return rc;
}

void runTeller(Teller *t){

}
