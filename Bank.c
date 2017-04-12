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

struct BANK Bank = {0,0,0,0,0,0,0,0};

int main(void) {
	initQueue();
	initTellers();



	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	doQueueAction();

	puts("!!!Hello World2!!!");

	destroyTellers();
	destroyQueue();
	return EXIT_SUCCESS;
}




