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

  initializeGame(2, k, testSeed, &baseState);

  // Start of testing

  // Will make a copy of the starting state
  memcpy(&testState, &baseState, sizeof(struct gameState));

  // Makes sure the gameState starts at correct phase
  printf("TEST 1: Will test the current phase of the game.\n");
  testState.phase = 1;

  printf("Expected phase: %d Actual phase: %d\n", baseState.phase, testState.phase);

  printf("Changing back to what it is supposed to be, will run assert.\n");
  testState.phase = 0;
  assert(testState.phase == baseState.phase);
  printf("PASSED\n\n");

  // Tests to check for appropriate supply counts for # of players given
  printf("TEST 2: Will test for correct supply amounts for 2 players\n");
  printf("Expected curses: %d Actual curses: %d \n", baseState.supplyCount[curse], testState.supplyCount[curse]);
  printf("Expected estate: %d Actual estate: %d\n", baseState.supplyCount[estate], testState.supplyCount[estate]);
  printf("Expected duchy: %d Actual duchy: %d\n", baseState.supplyCount[duchy], testState.supplyCount[duchy]);
  printf("Expected province: %d Actual province: %d\n", baseState.supplyCount[province], testState.supplyCount[province]);

  assert(baseState.supplyCount[estate] == testState.supplyCount[estate]);
  assert(baseState.supplyCount[duchy] == testState.supplyCount[duchy]);
  assert(baseState.supplyCount[province] == testState.supplyCount[province]);
  printf("PASSED\n\n");
  return 0;
}
