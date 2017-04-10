/*
 * customer.c
 *
 *  Created on: Apr 10, 2017
 *      Author: spm5065
 */

#include "customer.h"

void initCust( Customer *cust ){
	cust->timeInQueue = 0;
	cust->timeWithTeller = 0;
}

void bumpCustQueueTime(Customer *cust){
	cust->timeInQueue++;
}

void bumpCustTellerTime(Customer *cust){
	cust->timeWithTeller++;
}
