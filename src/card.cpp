/**
* @author Eric Sotkowy <sotkowy@uleth.ca>, Spencer Taylor
* @date 2020, 2020-09
*/

// this is the .cpp file for the implementation of the Card class

#include "../include/card.h"
#include <iostream>
#include <string>

// default constructor
Card::Card() :  _rank(0), _suit(0) {}

// defaul destructor
Card::~Card() {
}

// constructor gives value to _rank [1 - 13] and _suit [1 - 4]
Card::Card(const int& rank, const int& suit) : _rank(rank), _suit(suit) {}

// returns value of _rank
int Card::getRank() const {
  return _rank;
}

// returns value of _suit
int Card::getSuit() const {
  return _suit;
}

// overloaded operator to == check if card is a pair
bool Card::operator == (const Card& compare) const {
  if (this->getRank() == compare.getRank())
    return true;
  return false;
}

// overloaded operator to see if rank is greater than another card
bool Card::operator > (const Card& compare) const {
  if (this->getRank() > compare.getRank())
    return true;
  return false;
}

// overloaded operator to see if rank is less than another card
bool Card::operator < (const Card& compare) const {
  if (this->getRank() < compare.getRank())
    return true;
  return false;
}

// will cout card as "RANK of SUIT" of card
std::ostream& operator << (std::ostream& out, const Card& C) {
  const std::string SUIT[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  const std::string RANK[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
  "10", "Jack", "Queen", "King"};
  out <<  RANK[C.getRank()] + " of " + SUIT[C.getSuit()];
  return out;
}
