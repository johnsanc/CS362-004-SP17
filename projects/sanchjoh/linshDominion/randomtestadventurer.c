#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>



int main() {

  int p, n, i, result;
  struct gameState G;
  int drawCorrect, drawIncorrect, test1, test2, discardBefore,
      discardAfter, deckBefore, deckAfter, handBefore, handAfter, totalBefore,
      totalAfter, checkCard;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  // printf("Testing playAdventurer.\n");
  //
  // printf("Testing if correct card is drawn.\n");

  // Initiate ramdomizer
  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 10000; n++) {

    // Fill game post with random stuff.
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }

    // Fill game post with credible/in-range values
    // Since the Adventurer card relies on the ability to draw cards, we need
    // These values to stay within the allowabled ranges to accurately test.
    p = floor(Random() * 2);
    initializeGame(2, k, 1, &G);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);

    //result = checkAdventurerCard(p, &G);
    // Need to keep track of the amount in discard pile, deck size, hand size to
    // make sure amount are correct.  Hand will need to have +2 before function is
    // called because other cards are destroyed and 1 treasure cards are kept in
    // hand.
    handBefore = G.handCount[p];
    deckBefore = G.deckCount[p];
    discardBefore = G.discardCount[p];

    // Run the function
    checkCard = play_adventurer(&G);
    drawCorrect = G.hand[p][G.handCount[p] - 1];
    drawIncorrect = G.hand[p][G.handCount[p]];

    assert (checkCard == 0);
    // Get Results
    handAfter = G.handCount[p];
    deckAfter = G.deckCount[p];
    discardAfter = G.discardCount[p];

    // Run the totals
    totalBefore = handBefore + deckBefore + discardBefore;
    totalAfter = handAfter + deckAfter + discardAfter;

    // Testing if correct card was selected for cardDrawn
    if (drawIncorrect != drawCorrect) {
        test1 = 0;
    } else test1 = 1;

    // Testing if the totals for the cards in use had changed.
    if (totalBefore == totalAfter) {
        test2 = 1;
    } else test2 = 0;

    if (result == 1) {
        printf("ALL TESTS PASSED\n");
    } else if (result == -1) {
        printf("1 TEST PASSED OUT OF 2\n");
    } else {
        printf("ALL TESTS FAILED\n");
    }

  }


  return 0;
}
