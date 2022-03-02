#include "playerHand.h"
#include "oldMaid.h"
#include <iostream>

int main() {
  /*
  Deck testDeck;
  testDeck.shuffleDeck();
  PlayerHand testHand(testDeck, 17);
  testHand.sort();
  testHand.printHand();
  std::cout << '\n';
  testHand.printIndex();
  std::cout << '\n';
  for (size_t i = 0; i < testHand.size(); ++i)
    std::cout << i + 1 << ". " << testHand[i] << '\n';
  */
  oldMaid testGame;
  testGame.play();

  return 0;
}
