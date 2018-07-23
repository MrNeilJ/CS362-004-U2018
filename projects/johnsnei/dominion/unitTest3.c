/***************************************************
 * UNIT TEST # 1:
 * Tested Function: buyCard()
 *
 * Goal:
 * We will be confirming that the numBuy function
 * works according to the expected results to trying
 * to proceed down each of the potential paths the
 * function could take, as well as trying to design
 * som errors that could potentially occur while the
 * application is running.
 *
 ***************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv) {

	// Initialize the basics of the game
	struct gameState testGame;

	int k[10] = {
			adventurer,
			gardens,
			embargo,
			village,
			minion,
			mine,
			cutpurse,
			sea_hag,
			tribute,
			smithy
	};

	int numPlayers = 2;

	initializeGame(numPlayers, k, 10, &testGame);

	// Run through all the potential of the getCost() function

	// Actual values of all of the cards
	int currCard[11] = {6, 4, 2, 3, 5, 5, 4, 4, 5, 4, 6};
	int i;
	for (i = 0; i < 10; i++) {
		assert(getCost(k[i]) == currCard[i]);
	}
	
	// If we made it this far than everything is working.
	printf("UNIT TEST 3 PASSED");
	return 0;


}