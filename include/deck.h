/**
* @author Eric Sotkowy <sotkowy@uleth.ca>
* @date 2020, 2020-09
*/

// this is the header for the declaration of the Deck class

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "../include/card.h"

class Deck {
 public:
  Deck();
  Card draw();
  void shuffleDeck();
  bool isEmpty();
  int size();

  void printDeck();
 private:
  std::vector<Card> _deck;
};

#endif
