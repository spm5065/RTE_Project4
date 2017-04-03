/*
 * teller.c
 *
 *  Created on: Apr 3, 2017
 *      Author: spm5065
 */

#include "teller.h"

Teller *tellers[3];

void initTellers(){
	for( int i = 0; i < 3; i++){
		tellers[i] = (Teller *) malloc(sizeof(Teller));
		Teller *t = tellers[i];
		t->maxBreak 		= 0;
		t->minBreak		= 0;
		t->totalBreak	= 0;
		t->numBreaks		= 0;
		t->downTime		= 0;
		t->customerWith	= NULL;
	}
}

void destroyTellers(){
	for( int i = 0; i < 3; i++){
		free(tellers[i]);
	}
}
