/*
 * customer.h
 *
 *  Created on: Apr 3, 2017
 *      Author: spm5065
 */
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "stdhdr.h"
#include "teller.h"
#include "Randoms.h"

struct Teller;
typedef struct Customer Customer;

struct Customer {
	unsigned long 	 timeInQueue;
	unsigned long 	 timeWithTeller;
};

void initCust(Customer *cust);
void bumpCustQueueTime(Customer *cust);
void bumpCustTellerTime(Customer *cust);

#endif /* CUSTOMER_H_ */
