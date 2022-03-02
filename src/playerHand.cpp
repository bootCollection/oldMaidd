/**
* @author Eric Sotkowy <sotkowy@uleth.ca>, Spencer Taylor
* @date 2020, 2020-09
*/

// this is the .cpp file for the implementation of the PlayerHand class

#include "playerHand.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "../include/deck.h"
#include "../include/card.h"

//constructor function
PlayerHand :: PlayerHand() {}

// destructor class
PlayerHand :: ~PlayerHand() {
}
// returns the size of the hand
int PlayerHand::size() {
  return _hand.size();
}
// returns a card at a specific index i
const Card PlayerHand :: getCard(int i) {
  return _hand[i];
}

// will graphically print ASCII cards of the hand to terminal
void PlayerHand::printHand() {
  const std::string SUIT_SYM[4] = {"C", "D", "H", "S"};
  const std::string RANK_SYM[13] = {"A", "2", "3", "4", "5", "6", "7", "8",
  "9", "T", "J", "Q", "K"};

  if (!_hand.empty()) {
  unsigned int n = _hand.size() - 1;
  for (int i = 0; i < n; ++i) {
    std::cout << " ___";
  }
  std::cout << " _______ ";
  std::cout << '\n';

  for (int i = 0; i < n; ++i) {
    std::cout << "|   ";
  }
  std::cout << "|     " << RANK_SYM[_hand.back().getRank()]
  << SUIT_SYM[_hand.back().getSuit()] + "|";

  std::cout << '\n';
  for (int i = 0; i < n; ++i) {
    std::cout << "|   ";
  }
  std::cout << "|       |";
  std::cout << '\n';

  for (int i = 0; i < n; ++i) {
    std::cout << "|   ";
  }
  std::cout << "|   " << SUIT_SYM[_hand.back().getSuit()] << "   |";
  std::cout << '\n';
  for (int i = 0; i < n; ++i) {
    std::cout << "|   ";
  }
  std::cout << "|       |";
  std::cout << '\n';
  for (int i = 0; i < n; ++i)
    std::cout << "|" + RANK_SYM[_hand[i].getRank()]
    << SUIT_SYM[_hand[i].getSuit()] << '_';
    std::cout << "|" + RANK_SYM[_hand.back().getRank()]
    << SUIT_SYM[_hand.back().getSuit()] << "_____|";
  std::cout << '\n';
  } else {
    std::cout << "Hand is empty." << '\n';
  }
}

// will graphically print ASCII cards of the hand face-down to terminal
void PlayerHand::printHandFaceDown() {
  const std::string RANK_SYM[13] = {"A", "2", "3", "4", "5", "6", "7", "8",
  "9", "T", "J", "Q", "K"};
  if (!_hand.empty()) {
  unsigned int n = _hand.size() - 1;
  for (int i = 0; i < n; ++i) {
    std::cout << " ___";
  }
  std::cout << " _______ " << " ";
  std::cout << '\n';

  for (int i = 0; i < n; ++i)
    std::cout << "|   ";
  std::cout << "|     " << "  |";

  std::cout << '\n';
  for (int i = 0; i < n; ++i)
    std::cout << "|   ";
  std::cout << "|       |";
  std::cout << '\n';

  for (int i = 0; i < n; ++i)
    std::cout << "|   ";
  std::cout << "|       |";
  std::cout << '\n';
  for (int i = 0; i < n; ++i)
    std::cout << "|   ";
  std::cout << "|       |";
  std::cout << '\n';
  for (int i = 0; i < n; ++i)
    std::cout << "|___";
  std::cout << "|_______|";
  std::cout << '\n';
  } else {
    std::cout << "Hand is empty" << '\n';
  }
}

// will print the numbered index of the cards to the terminal
void PlayerHand::printIndex() {
  for (size_t i = 1; i < size() + 1; ++i) {
    if (i < 10)
      std::cout << i << ".  ";
    else
      std::cout << i << ". ";
  }
  std::cout << '\n';
}

// will sort the hand from lowest -> highest
void PlayerHand::sort() {
  std::sort(_hand.begin(), _hand.end());
}

// pushes a card into the hand
void PlayerHand :: push(const Card& c) {
  _hand.push_back(c);
}
// removes a card at a specific index
void PlayerHand :: remove(int i) {
  _hand.erase(_hand.begin()+i);  //i-1?
}

// overloaded operator to return a card at the index
Card& PlayerHand::operator[] (int index) {
  return _hand[index];
}
