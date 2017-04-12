/*
 * metrics.c
 *
 *  Created on: Apr 8, 2017
 *      Author: smd6141
 */

#include "bank.h"

void calculate_metrics(){

	//Total Customers Serviced
	printf("Total Customers Serviced %lu/n " , Bank.customersServiced);

	//Average Queue Time
	printf("Average Queue Time %lu/n " , Bank.totalTimeInQueue/customersServiced);

	//Maximim Queue Time
	printf("Maximim Queue Time %lu/n ", Bank.maxTimeInQueueCust );

	//Average Transaction Time
	printf("Average Transaction Time %lu/n ", Bank.totalTimeWithTellers/customersServiced );

	//Maximim Transaction Time
	printf("Maximim Transaction Time %lu/n ", Bank.maxTimeInTransaction );

	//Average Teller Idle Time
	printf("Average Teller Idle Time %lu/n ", Bank.totalTellerDowntime/3 );

	//Longent Line
	printf("Longent Line %lu/n ", Bank.maxNumInQueue );

	//Total Breaks Per
	printf("Teller One Total Breaks %lu/n ", tellers[0].numBreaks );
	printf("Teller Two Total Breaks %lu/n ", tellers[1].numBreaks );
	printf("Teller Three Total Breaks %lu/n ", tellers[2].numBreaks );

	//Average breaks Per
	printf("Teller One Average breaks %lu/n ", (tellers[0].totalBreak)/(tellers[0].numBreaks) );
	printf("Teller Two Average breaks %lu/n ", (tellers[1].totalBreak)/(tellers[1].numBreaks) );
	printf("Teller Three Average Breaks %lu/n ", (tellers[2].totalBreak)/(tellers[2].numBreaks) );

	//Longest Break Per
	printf("Teller One Longest Break %lu/n ", tellers[0].maxBreak );
	printf("Teller Two Longest Break %lu/n ", tellers[1].maxBreak );
	printf("Teller Three TLongest Break %lu/n ", tellers[2].maxBreak );

	//Shortest Break Per
	printf("Teller One Shortest Break %lu/n ", tellers[0].minBreak );
	printf("Teller Two Shortest Break %lu/n ", tellers[1].minBreak );
	printf("Teller Three Shortest Break %lu/n ", tellers[2].minBreak );
}
