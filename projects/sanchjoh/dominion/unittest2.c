#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

  struct gameState baseState, testState;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  int testSeed = 1000;
  int card1 = adventurer, card2 = smithy;
  int testResult, baseResult;

  initializeGame(2, k, testSeed, &baseState);

  // Start of testing

  // Will make a copy of the starting state
  memcpy(&testState, &baseState, sizeof(struct gameState));

  printf("TEST 1: Show set data before calling function\n");
  printf("Showing test number of coins before: %d\n", testState.coins);
  printf("Showing base number of coins before: %d\n", baseState.coins);
  printf("Showing test number of actions before: %d\n", testState.numActions);
  printf("Showing base number of actions before: %d\n", baseState.numActions);
  assert(baseState.numActions == testState.numActions);
  printf("PASSED\n");

  printf("TEST 2: Will test if the card was played using initialized results.\n");
  testResult = playCard(0, 0, 1, 2, &testState);
  baseResult = playCard(0, 0, 1, 2, &testState);
  printf("Expected result: %d Actual Result: %d\n", baseResult, testResult);

  if (testResult == -1) {
    printf("TEST FAILED (CARD NOT PLAYED)\n");
  } else {
    printf("PASSED\n");
  }

  printf("TEST 3: Show set data after calling function\n");
  printf("Showing test number of coins after: %d\n", testState.coins);
  printf("Showing base number of coins after: %d\n", baseState.coins);
  printf("Showing test number of actions after: %d\n", testState.numActions);
  printf("Showing base number of actions after: %d\n", baseState.numActions);
  assert(baseState.numActions == testState.numActions);
  printf("PASSED\n\n");

  return 0;
}
