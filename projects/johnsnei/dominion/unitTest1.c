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

	/* NumBuys potential errors that could occur
	 * Return -1 (Not enough buys available)
	 * Return -1 (There are not any cards of that type left)
	 * Return -1 (Player doesn't have enough money to buy that item)
	 * Return 0  (Completed the function all the way to the end properly)
	*/

	// Initialize the basics of the game
	struct gameState testGame;
	int player;
	int i;
	int k[10];
	for (i = 0; i < 10; i++) {
		k[i] = i+1;
	}

	/*int k[10] = {
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
*/
	int numPlayers = 2;

	initializeGame(2, k, numPlayers, &testGame);

	// TESTING TO SEE IF THE GAME CAN HANDLE A CHARACTER WITH 0 BUYS
	testGame.numBuys = 0;

	// MATCH HOW THE BUY CARD FUNCTION WORKS IN THE DOMINION FILE
	player = buyCard(5, &testGame);

	// Did we receive any error since the user does not have any available buys
	assert(player == -1);

	// Check to see if we can fail due to not enough money
	testGame.coins = 0;

	player = buyCard(5, &testGame);

	assert(player == -1);

	// Check to see if we can fail due to incorrect choices
	player = buyCard(-1, &testGame);

	assert(player == -1);

	// Now just to make sure everything isn't broken
	testGame.coins = 15;

	player = buyCard(5, &testGame);

	assert (player == 0);

	// If we made it this far than everything is working.
	printf("Success");
	return 0;


}