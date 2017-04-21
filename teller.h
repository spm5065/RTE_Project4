/*
 * teller.h
 *
 *  Created on: Apr 3, 2017
 *      Author: spm5065
 */
#ifndef TELLER_H_
#define TELLER_H_

#include "stdhdr.h"
#include "customer.h"
#include "Randoms.h"


struct Customer;

typedef struct Teller Teller;
struct Teller {
	unsigned long 	maxBreak;		//Time of longest break
	unsigned long 	minBreak;		//Time of shortest break
	unsigned long 	totalBreak;	//Total break time
	unsigned int 	numBreaks;		//Number of breaks
	unsigned long 	downTime;		//Time Teller has been waiting for customers
	struct Customer	   *customerWith;
	int 			tellerNum;
	unsigned long	timeRem;
	long			timeToBreak;
	long			timeLeftOnBreak;
};

//void runTeller(&);

void initTellers();
void destroyTellers();
void runTeller( Teller *t );

extern Teller *tellers[3];

#endif /* TELLER_H_ */
