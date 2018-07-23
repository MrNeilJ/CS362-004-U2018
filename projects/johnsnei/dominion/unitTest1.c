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

	printf("UNIT 1 TESTING:\n");

	/* NumBuys potential errors that could occur
	 * Return -1 (Not enough buys available)
	 * Return -1 (There are not any cards of that type left)
	 * Return -1 (Player doesn't have enough money to buy that item)
	 * Return 0  (Completed the function all the way to the end properly)
	*/

	// Initialize the basics of the game
	struct gameState testGame;
	int player;

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

	// TESTING TO SEE IF THE GAME CAN HANDLE A CHARACTER WITH 0 BUYS
	testGame.numBuys = 0;

	// MATCH HOW THE BUY CARD FUNCTION WORKS IN THE DOMINION FILE
	player = buyCard(village, &testGame);

	// Did we receive any error since the user does not have any available buys
	if (player == -1) {
		printf("Correct: Error received when user has 0 buys\n");
	}
	// assert(player == -1);

	// Check to see if we can fail due to not enough money
	testGame.coins = 0;

	player = buyCard(village, &testGame);
	if (player == -1) {
		printf("Correct: Error received when user has 0 buys\n");
	}
	else {
		printf("Incorrect: Did not receive -1 when out of money\n");
	}

	//assert(player == -1);

	// Check to see if we can fail due to incorrect choices
	player = buyCard(-1, &testGame);

	//assert(player == -1);
	if (player == -1) {
		printf("Correct: Error received with incorrect choices are made\n");
	}
	else {
		printf("Incorrect: Did not receive an error when making a wrong choice\n");
	}

	// Now just to make sure everything isn't broken
	testGame.numBuys = 2;
	testGame.coins = 15;

	player = buyCard(village, &testGame);

	if (player == 0) {
		printf("Correct: Passes when it is supposed to pass\n");
	}
	else {
		printf("Incorrect: Received an error with passing results\n");
	}

	//assert (player == 0);

	// If we made it this far than everything is working.
	//printf("UNIT TEST 1 PASSED\n\n");
	return 0;


}