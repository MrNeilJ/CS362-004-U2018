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


	// Set the game up so that the smithy card is in the 0 position
	testGame.hand[0][0] = smithy;

	// Prep it so that we an definitely play the card
	testGame.numActions = 2;
	testGame.phase = 0;

	// Get the amount of cards in hand before playing the smithy card
	int currCards = numHandCards(&testGame);
	int currActions = testGame.numActions;

	// Play the Smithy Card
	int cardPlay = cardEffect(0, 0, 0, 0, &testGame, NULL);

	if (cardPlay == 0) {
		printf("Testing to ensure correct amount of cards.");
		assert((currCards + 2) == numHandCards(&testGame));
		printf("Total card amount was correct");

		printf("Testing to ensure actions decreased.");
		assert((currActions - 1 ) == testGame.numActions);
		printf("Number of actions were correct");
	}

	// If we made it this far than everything is working.
	printf("Success, passed all tests");
	return 0;


}