#pragma once

unsigned char RandomNextCustomerTime();	//Get time for next customer to appear in queue in minutes
unsigned short RandomTransactionTime();	//Get time to service a customer in increments of 30seconds
unsigned short RandomBreakLength();		//Get length of next break ( 1 to 4 min)
unsigned short RandomBreakTime();		//Get time of next break in minutes (30 min to 60 min)









