/*
 ============================================================================
 Name        : Bank.c
 Author      : Sergio Martins and Spencer Dennis
 Version     :
 Copyright   : 2017
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "stdhdr.h"
#include "teller.h"
#include "customer.h"
#include "queue.h"

struct Bank {
	unsigned long 	customersServiced;
	unsigned long 	totalTimeInQueue;
	unsigned long 	totalTimeWithTellers;
	unsigned long	totalTellerDowntime;
	unsigned int 	numInQueue;
	unsigned long	maxTimeInQueueCust;
	unsigned long	maxTimeInTransaction;
	unsigned int 	maxNumInQueue;
} Bank = {0,0,0,0,0,0,0,0};

int main(void) {
	initTellers();
	initQueue();


	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */


	destroyQueue();
	destroyTellers();
	return EXIT_SUCCESS;
}




