/*
 * metrics.c
 *
 *  Created on: Apr 8, 2017
 *      Author: smd6141
 */

#include "metrics.h"

//time stored in 30 sec increments divide by 2 for minutes and cast to float for accuracy
void calculate_metrics(){

	//Total Customers Serviced
	printf(" Total Customers Serviced: %lu\r\n " , Bank.customersServiced);

	//Average Queue Time
	printf("Average Queue Time: %f minutes\r\n " , ((float)((Bank.totalTimeInQueue/2.)/ (float) Bank.customersServiced))/2. );

	//Maximum Queue Time
	printf("Maximum Queue Time: %f minutes\r\n ", ((float)Bank.maxTimeInQueueCust)/2. );

	//Longest Line
	printf("Longest Line: %lu\r\n ", Bank.maxNumInQueue );

	//Average Transaction Time
	printf("Average Transaction Time: %f minutes\r\n ", ((float)(Bank.totalTimeWithTellers/(float)Bank.customersServiced))/2. );

	//Maximum Transaction Time
	printf("Maximum Transaction Time: %f minutes\r\n ", ((float)Bank.maxTimeInTransaction)/2. );

	//Average Teller Idle Time
	printf("Average Teller Idle Time: %f minutes\r\n ", (((float)Bank.totalTellerDowntime)/((float)Bank.totalTellerIdles))/2. );

	if (1){
		//Total Breaks Per
		for(int i = 0; i < 3; i++)
			printf("Teller %d Total Breaks: %d\r\n ", tellers[i]->tellerNum, tellers[i]->numBreaks );

		//Average break Per
		for(int i = 0; i < 3; i++)
			printf("Teller %d Average Break: %f minutes\r\n ", tellers[i]->tellerNum, ((float)(tellers[i]->totalBreak)/((float)tellers[i]->numBreaks))/2. );

		//Longest Break Per
		for(int i = 0; i < 3; i++)
			printf("Teller %d Longest Break: %f minutes\r\n ", tellers[i]->tellerNum, ((float)tellers[i]->maxBreak)/2. );

		//Shortest Break Per
		for(int i = 0; i < 3; i++)
			printf("Teller %d Shortest Break: %f minutes\r\n ", tellers[i]->tellerNum, ((float)tellers[i]->minBreak)/2. );
	}
}
