#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

int checkSmithy(struct gameState *state, int p) {
  struct gameState correct;
  memcpy(&correct, state, sizeof(struct gameState));

  int result;

  result = playSmithy(state, 0);


  if (correct.deckCount[p] > 0) {
    int counter = 0;
    // Simulate drawing 3 cards
    while (correct.deckCount[p] > 0 && counter < 3) {
      correct.deckCount[p]--;
      correct.handCount[p]++;
      counter++;
    }
    // Simulate discarding a card from hand
    correct.handCount[p]--;
    correct.discardCount[p]++;
  }

  if (correct.deckCount[p] < state->deckCount[p]){
    // printf("TEST1 FAILED\n");
    return 0;
  }
  if (correct.discardCount[p] > state->discardCount[p]) {
    // printf("TEST2 FAILED\n");
    return 0;
  }
  if (correct.handCount[p] > state->handCount[p]) {
    // printf("TEST3 FAILED\n");
    return 0;
  }

  return 1;
}

int main() {
  int p, n, i, result;
  struct gameState G;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  // Initiate ramdomizer
  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {

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
    result = checkSmithy(&G, p);
  }

  if (result == 0) {
    printf("SMITHY FAILED\n");
  } else {
    printf("SMITHY PASSED\n");
  }
}
