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
		t->minBreak			= 0;
		t->totalBreak		= 0;
		t->numBreaks		= 0;
		t->downTime			= 0;
		t->customerWith		= NULL;
		t->tellerNum 		= i+1;
		t->timeRem			= 0;
		t->timeToBreak		= 0;
		t->timeLeftOnBreak	= 0;
	}
}

void destroyTellers(){
	for( int i = 0; i < 3; i++){
		free(tellers[i]);
	}
}

//a single teller turn, that ensures it is their turn
int doTellerAction(Teller *t){
	int turn = -1;	//Value for turn
	int rc = 1;		//Return Code

	//Get the turn, and check if its my turn
	if( sem_getvalue( &turnSemaphore, &turn ) == 0 && ( (turn % 4 == t->tellerNum) || (turn == 0) ) ){


		//No Customer
		if(t->customerWith == NULL){

			if(--t->timeToBreak > 0) {
				//If people in queue, get customer
				if(getQueueSize()){
					t->customerWith = popQueue();
					t->timeRem = RandomTransactionTime();
					t->customerWith->timeWithTeller = t->timeRem;
//					Bank.customersServiced++;
//					Bank.totalTimeInQueue += t->customerWith->timeInQueue;
//					Bank.totalTimeWithTellers += t->customerWith->timeWithTeller;
//					if(t->customerWith->timeInQueue > Bank.maxTimeInQueueCust) Bank.maxTimeInQueueCust = t->customerWith->timeInQueue;
//					if(t->customerWith->timeWithTeller > Bank.maxTimeInTransaction) Bank.maxTimeInTransaction = t->customerWith->timeWithTeller;

				//else check if we need to continue
				} else {
					if(turn != 0)
						t->downTime++;
					else {
						Bank.totalTellerDowntime += t->downTime;
						rc = 0;
					}
				}
			} else {
				if(--t->timeLeftOnBreak <= 0) {
					t->timeToBreak = RandomBreakTime();
					t->timeLeftOnBreak = RandomBreakLength();
					t->numBreaks++;

					if(t->maxBreak < t->timeLeftOnBreak || t->maxBreak == 0) t->maxBreak = t->timeLeftOnBreak;
					if(t->minBreak > t->timeLeftOnBreak || t->minBreak == 0) t->minBreak = t->timeLeftOnBreak;
					t->totalBreak += t->timeLeftOnBreak;
				}
			}

		} else {

			if(--t->timeRem == 0){

				//FinishTransaction
				if(t->customerWith->timeWithTeller > Bank.maxTimeInTransaction)
					Bank.maxTimeInTransaction = t->customerWith->timeWithTeller;

				if(t->customerWith->timeInQueue > Bank.maxTimeInQueueCust)
					Bank.maxTimeInQueueCust = t->customerWith->timeInQueue;

				Bank.totalTimeWithTellers += t->customerWith->timeWithTeller;
				Bank.customersServiced++;
				Bank.totalTimeInQueue += t->customerWith->timeInQueue;

				free(t->customerWith);
				t->customerWith = NULL;
			}
		}

		if (turn != 0) sem_wait(&turnSemaphore);

	}

	struct timespec time;
	time.tv_sec = 0;
	time.tv_nsec = 5000;
	nanosleep(&time, NULL);

	return rc;

}

//Do action until done
void runTeller(Teller *t){
	int i = 0;
	 while( doTellerAction(t) && i < 100000 ) {i++;};
	 printf("Teller %d is leaving for day...\r\n", t->tellerNum);
}
