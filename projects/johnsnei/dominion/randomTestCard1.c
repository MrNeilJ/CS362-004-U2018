#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include "dominion_helpers.h"

#define NUM_TESTS 100

// This randomly tests Adventurer
int smithyCardTest(struct gameState *pre, struct gameState *post, int player) {
	// Check to see if we have gained at least two treasure cards
	int preHandCount = pre->handCount[player];
	int postHandCount = post->handCount[player];

	int preDeckCount = pre->deckCount[player];

	if(preDeckCount >= 3) {
		if (preHandCount + 2 == postHandCount) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		if (preDeckCount == 0) {
			if (preHandCount == postHandCount - 1) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else {
			if (preHandCount + preDeckCount == postHandCount + 1) {
				return 0;
			}
			else {
				return 1;
			}
		}
	}



}


int main() {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
				 sea_hag, tribute, smithy};
	int numPlayers;
	int player;
	int seed;
	int handPos;
	int coinBonus;
	int result = 0;

	// Game setup
	struct gameState pre;
	struct gameState post;

	srand(time(NULL));

	printf("--------------------------------------------------------------------------------\n");
	printf("RANDOM SMITHY TEST:\n");
	printf("Testing to validate we get the correct number of cards after playing\n");

	for (int i = 0; i < NUM_TESTS; i++) {

		// Randomize the elements to build the game
		numPlayers = 2;
		seed = rand();
		coinBonus = 0;
		// Allow the test to flip flop between players
		player = i % (numPlayers);

		// Alter hand position on a randomized basis as well (max 4 since that's the starting hand)
		handPos = rand() % 4;

		initializeGame(numPlayers, k, seed, &post); //initialize Gamestate

		// Initiate valid post variables
		post.whoseTurn = player;
		post.deckCount[player] = rand() % MAX_DECK;   //Pick random deck size out of MAX DECK size
		post.discardCount[player] = rand() % MAX_DECK;
		post.handCount[player] = rand() % MAX_HAND;


		// Copy all of the settings so we can see what occurs after the card is played
		pre = post;

		int cardPlay = cardEffect(smithy, 1, 1, 1, &post, handPos, &coinBonus);
		if (cardPlay == -1) {

		}

		// Check to see if we failed our test
		result += smithyCardTest(&pre, &post, player);

	}
	if (result >= 1) {
		printf("Smithy failed %d times, check your code and try again\n", result);
	}
	else {
		printf("Smithy Card passed, no oddities could be recreated");
	}
	printf("--------------------------------------------------------------------------------\n");

	return 0;
}