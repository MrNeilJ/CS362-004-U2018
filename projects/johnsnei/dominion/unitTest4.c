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

	printf("\nUNIT 4 TESTING:\n");
	/* NumBuys potential errors that could occur
	 * Return -1 (Not enough buys available)
	 * Return -1 (There are not any cards of that type left)
	 * Return -1 (Player doesn't have enough money to buy that item)
	 * Return 0  (Completed the function all the way to the end properly)
	*/

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

	// Run through all the potential of the whoseTurn() function options

	// Lets see if it starts with the correct player
	int currentPlayer = 0;
	//assert(currentPlayer == whoseTurn(&testGame));
	if (currentPlayer == whoseTurn(&testGame)) {
		printf("Correct: Player matches correct turn\n");
	}
	else {
		printf("Incorrect: Player and current player do not match\n");
	}

	// End the turn and then test again.
	endTurn(&testGame);
	//assert(currentPlayer != testGame.whoseTurn);
	if (currentPlayer != whoseTurn(&testGame)) {
		printf("Correct: Players have now switched\n");
	}
	else {
		printf("Incorrect: Player and current player still match\n");
	}

	
	// If we made it this far than everything is working.
	//printf("UNIT TEST 4 PASSEED\n");
	return 0;


}