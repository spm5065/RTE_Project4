/*
 * metrics.c
 *
 *  Created on: Apr 8, 2017
 *      Author: smd6141
 */

#include "bank.h"
//time stored in 30 sec increments divide by 2 for minutes and cast to float for accuracy
void calculate_metrics(){

	//Total Customers Serviced
	printf("Total Customers Serviced: %f/n " , (float)Bank.customersServiced);

	//Average Queue Time
	printf("Average Queue Time: %f minutes/n " , ((float)(Bank.totalTimeInQueue/customersServiced))/2 );

	//Maximim Queue Time
	printf("Maximim Queue Time: %f minutes/n ", ((float)Bank.maxTimeInQueueCust)/2 );

	//Average Transaction Time
	printf("Average Transaction Time: %f minutes/n ", ((float)(Bank.totalTimeWithTellers/customersServiced))/2 );

	//Maximim Transaction Time
	printf("Maximim Transaction Time: %f minutes/n ", ((float)Bank.maxTimeInTransaction)/2 );

	//Average Teller Idle Time
	printf("Average Teller Idle Time: %f minutes/n ", ((float)Bank.totalTellerDowntime/3)/2 );

	//Longent Line
	printf("Longent Line: %f/n ", (float)Bank.maxNumInQueue );

	//Total Breaks Per
	printf("Teller One Total Breaks: %f/n ", (float)tellers[0].numBreaks );
	printf("Teller Two Total Breaks: %f/n ", (float)tellers[1].numBreaks );
	printf("Teller Three Total Breaks: %f/n ", (float)tellers[2].numBreaks );

	//Average break Per
	printf("Teller One Average Break: %f minutes/n ", ((float)(tellers[0].totalBreak)/(tellers[0].numBreaks))/2 );
	printf("Teller Two Average Break: %f minutes/n ", ((float)(tellers[1].totalBreak)/(tellers[1].numBreaks))/2 );
	printf("Teller Three Average Break: %f minutes/n ", ((float)(tellers[2].totalBreak)/(tellers[2].numBreaks))/2 );

	//Longest Break Per
	printf("Teller One Longest Break: %f minutes/n ", ((float)tellers[0].maxBreak)/2 );
	printf("Teller Two Longest Break: %f minutes/n ", ((float)tellers[1].maxBreak)/2 );
	printf("Teller Three TLongest Break: %f minutes/n ", ((float)tellers[2].maxBreak)/2 );

	//Shortest Break Per
	printf("Teller One Shortest Break: %f minutes/n ", ((float)tellers[0].minBreak)/2 );
	printf("Teller Two Shortest Break: %f minutes/n ", ((float)tellers[1].minBreak)/2 );
	printf("Teller Three Shortest Break: %f minutes/n ", ((float)tellers[2].minBreak)/2 );
}
