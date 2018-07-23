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
	printf("\nCARDTEST 4 TESTING:\n");

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
			council_room,
			smithy
	};

	int numPlayers = 2;

	initializeGame(numPlayers, k, 10, &testGame);


	// Set the game up so that the smithy card is in the 0 position
	testGame.hand[0][0] = adventurer;

	// Prep it so that we an definitely play the card
	testGame.numActions = 2;
	testGame.phase = 0;

	// Get the amount of cards in hand before playing the smithy card
	int currCards = numHandCards(&testGame);
	int currBuys = testGame.numBuys;

	//printf("Current Cards: %d\n", currCards);
	//printf("Current Buys: %d\n", currBuys);



	// Play the Smithy Card
	int cardPlay = cardEffect(adventurer, 0, 0, 0, &testGame, 0, NULL);

	if (cardPlay == 0) {
		//printf("Testing to ensure correct amount of cards.\n");
		//printf("Current Cards: %d\n", numHandCards(&testGame));

		//assert((currCards + 2) == numHandCards(&testGame));
		if ((currCards + 2) == numHandCards(&testGame)) {
			printf("Correct: Council Room Produces the correct number of cards\n");
		}
		else {
			printf("Incorrect: Council Room produces incorrect number of cards\n");
		}
		//printf("Total card amount was correct\n");



	}

	// If we made it this far than everything is working.
	//printf("CARDTEST4 PASSED\n");
	return 0;


}