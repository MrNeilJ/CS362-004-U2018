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
int adventureCardTest(struct gameState *pre, struct gameState *post, int player, int prevHandCount, int prevDeckCount) {
	// Check to see if we have gained at least two treasure cards
	int preDrawnTreasures 	= 0;
	int postDrawnTreasures 	= 0;
	int preHandCount = pre->handCount[player];
	int postHandCount = post->handCount[player];

	int n;

	for(n = 0; n < pre->handCount[player]; n++){
		if(pre->hand[player][n] == copper || pre->hand[player][n] == silver || pre->hand[player][n] == gold){
			preDrawnTreasures++;
		}
	}

	for(n = 0; n < pre->handCount[player]; n++){
		if(post->hand[player][n] == copper || post->hand[player][n] == silver || post->hand[player][n] == gold){
			postDrawnTreasures++;
		}
	}

	if ((preDrawnTreasures + 2 == postDrawnTreasures) && (preHandCount < postHandCount)) {
		return 0;
	}
	else {
		return 1;
	}

}


int main() {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
				 sea_hag, tribute, smithy};
	int numPlayers;
	int player;
	int handCount;
	int deckCount;
	int seed;
	int handPos;
	int coinBonus;
	int result;

	// Game setup
	struct gameState pre;
	struct gameState post;

	srand(time(NULL));

	printf("--------------------------------------------------------------------------------\n");
	printf("RANDOM ADVENTURER TEST:\n");
	printf("Testing to validate we get the correct number of cards after playing");

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
		post.deckCount[player] = rand() % MAX_DECK;   //Pick random deck size out of MAX DECK size
		post.discardCount[player] = rand() % MAX_DECK;
		post.handCount[player] = rand() % MAX_HAND;

		// Copy post variables
		handCount = post.handCount[player];
		deckCount = post.deckCount[player];

		// Copy all of the settings so we can see what occurs after the card is played
		pre = post;

		int cardPlay = cardEffect(adventurer, 1, 1, 1, &post, handPos, &coinBonus);
		if (cardPlay == -1) {
			result += 1;
		}

		// Check to see if we failed our test
		//result += adventureCardTest(&pre, &post, player, handCount, deckCount);



		// Check to see if we have gained at least two treasure cards
		int preDrawnTreasures 	= 0;
		int postDrawnTreasures 	= 0;
		int preHandCount = pre.handCount[player];
		int postHandCount = post.handCount[player];

		int n;

		for(n = 0; n < pre.handCount[player]; n++){
			if(pre.hand[player][n] == copper || pre.hand[player][n] == silver || pre.hand[player][n] == gold){
				preDrawnTreasures++;
			}
		}

		for(n = 0; n < pre.handCount[player]; n++){
			if(post.hand[player][n] == copper || post.hand[player][n] == silver || post.hand[player][n] == gold){
				postDrawnTreasures++;
			}
		}

		if ((preDrawnTreasures < postDrawnTreasures) && (preHandCount < postHandCount)) {
			result += 0;
		}
		else {
			result += 1;
		}




	}



	printf("Tests Complete\n");
	if (result >= 1) {
		printf("Adventurer failed %d times, check your code and try again\n", result);
	}
	else {
		printf("Adventurer Card passed, no oddities could be recreated");
	}
	printf("--------------------------------------------------------------------------------");

	return 0;
}