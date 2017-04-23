/*
 * Randoms.c
 *
 *  Created on: Mar 27, 2017
 *      Author: spm5065
 */

#include <stdio.h>
#include <stdlib.h>
#include "Randoms.h"

//Get time for next customer to appear in queue
unsigned char RandomNextCustomerTime(){
	return (char) (( rand() % 8 + 1));
}

//Get time to service a customer in increments of 30seconds ( 30 seconds to 8 minutes )
unsigned short RandomTransactionTime(){
	return (short) ( rand() % 16 + 1 );
}

//Get length of next break ( 1 to 4 min)
unsigned short RandomBreakLength(){
	return (short) ((rand() % 7 + 2));
}

//Get time of next break (30 min to 60 min) in increments of 30 seconds
unsigned short RandomBreakTime(){
	return(short) ((rand() % 61 + 60));
}

