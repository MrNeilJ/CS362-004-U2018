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

	// Check to see if the game is still playing
	//int endedYet = isGameOver(&testGame);
	assert(isGameOver(&testGame) == 0);

	// Change a value to have the game end
	testGame.supplyCount[province] = 0;
	//endedYet = isGameOver(&testGame);
	//assert(endedYet == 1);
	assert(isGameOver(&testGame) == 1);


	// Reinitialize to check again
	initializeGame(numPlayers, k, 10, &testGame);
	//endedYet = isGameOver(&testGame);

	int i;
	for (i = 0; i < 3; i++) {
		testGame.supplyCount[i] = 0;
	}
	//endedYet = isGameOver(&testGame);
	//assert(endedYet == 1);
	assert(isGameOver(&testGame) == 1);

	// If we made it this far than everything is working.
	printf("UNIT TEST 2 PASSED");
	return 0;


}