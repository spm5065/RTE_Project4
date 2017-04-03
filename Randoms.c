/*
 * Randoms.c
 *
 *  Created on: Mar 27, 2017
 *      Author: spm5065
 */

#include <stdio.h>
#include <stdlib.h>

//Get time for next customer to appear in queue in minutes
unsigned char RandomNextCustomerTime(){
	return ((char) rand() % 4 + 1);
}

//Get time to service a customer in increments of 30seconds
unsigned short RandomTransactionTime(){
	return ((short) rand() % 16 + 1 );
}
