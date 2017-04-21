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
	printf(" Total Customers Serviced: %f\r\n " , (float)Bank.customersServiced);

	//Average Queue Time
	printf("Average Queue Time: %f minutes\r\n " , ((float)(Bank.totalTimeInQueue/ (float) Bank.customersServiced))/2. );

	//Maximum Queue Time
	printf("Maximum Queue Time: %f minutes\r\n ", ((float)Bank.maxTimeInQueueCust)/2. );

	//Average Transaction Time
	printf("Average Transaction Time: %f minutes\r\n ", ((float)(Bank.totalTimeWithTellers/(float)Bank.customersServiced))/2. );

	//Maximum Transaction Time
	printf("Maximum Transaction Time: %f minutes\r\n ", ((float)Bank.maxTimeInTransaction)/2. );

	//Average Teller Idle Time
	printf("Average Teller Idle Time: %f minutes\r\n ", (((float)Bank.totalTellerDowntime)/3.)/2. );

	//Longest Line
	printf("Longest Line: %f\r\n ", (float)Bank.maxNumInQueue );

	//Total Breaks Per
	printf("Teller One Total Breaks: %f\r\n ", (float)tellers[0]->numBreaks );
	printf("Teller Two Total Breaks: %f\r\n ", (float)tellers[1]->numBreaks );
	printf("Teller Three Total Breaks: %f\r\n ", (float)tellers[2]->numBreaks );

	//Average break Per
	printf("Teller One Average Break: %f minutes\r\n ", ((float)(tellers[0]->totalBreak)/((float)tellers[0]->numBreaks))/2. );
	printf("Teller Two Average Break: %f minutes\r\n ", ((float)(tellers[1]->totalBreak)/((float)tellers[1]->numBreaks))/2. );
	printf("Teller Three Average Break: %f minutes\r\n ", ((float)(tellers[2]->totalBreak)/((float)tellers[2]->numBreaks))/2. );

	//Longest Break Per
	printf("Teller One Longest Break: %f minutes\r\n ", ((float)tellers[0]->maxBreak)/2. );
	printf("Teller Two Longest Break: %f minutes\r\n ", ((float)tellers[1]->maxBreak)/2. );
	printf("Teller Three TLongest Break: %f minutes\r\n ", ((float)tellers[2]->maxBreak)/2. );

	//Shortest Break Per
	printf("Teller One Shortest Break: %f minutes\r\n ", ((float)tellers[0]->minBreak)/2. );
	printf("Teller Two Shortest Break: %f minutes\r\n ", ((float)tellers[1]->minBreak)/2. );
	printf("Teller Three Shortest Break: %f minutes\r\n ", ((float)tellers[2]->minBreak)/2. );
}
