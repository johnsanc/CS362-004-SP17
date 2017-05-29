int drawCorrect, drawIncorrect, test1, test2, discardBefore,
      discardAfter, deckBefore, deckAfter, handBefore, handAfter, totalBefore,
      totalAfter, checkCard;

  // Need to keep track of the amount in discard pile, deck size, hand size to
  // make sure amount are correct.  Hand will need to have +2 before function is
  // called because other cards are destroyed and 1 treasure cards are kept in
  // hand.
  handBefore = G.handCount[p];
  deckBefore = G.deckCount[p];
  discardBefore = G.discardCount[p];

  // Run the function
  checkCard = playAdventurer(G);
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

  // Results of TESTS
  if (test1 == 1 && test2 == 1) {
    return 1;
  } else if ((test1 == 0 && test2 == 1) || (test1 == 1 && test2 == 0)) {
    return -1;
  } else return 0;

