/*
 * Bank.h
 *
 *  Created on: Apr 12, 2017
 *      Author: spm5065
 */

#ifndef BANK_H_
#define BANK_H_


struct BANK {
	unsigned long 	customersServiced;
	unsigned long 	totalTimeInQueue;
	unsigned long 	totalTimeWithTellers;
	unsigned long	totalTellerDowntime;
	unsigned long	totalTellerIdles;
	unsigned long 	numInQueue;
	unsigned long	maxTimeInQueueCust;
	unsigned long	maxTimeInTransaction;
	unsigned long 	maxNumInQueue;
} extern Bank;

#endif /* BANK_H_ */
