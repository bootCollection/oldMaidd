/**
* @author Eric Sotkowy, Spencer Taylor <sotkowy@uleth.ca>
* @date 2020, 2020-09
*/

// this is the .cpp file for the implementation of the Deck class

#include "../include/deck.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <random>

// default constructor fills deck with standard 52 playing cards and then
// removes one random queen from the deck (total final card count of 51)
Deck::Deck() {
  for (size_t i = 0; i < 4; ++i)
    for (size_t j = 0; j < 13; ++j)
      _deck.push_back(Card(j, i));
  std::sort(_deck.begin(), _deck.end());
  time_t t;
  srand(time(&t));
  int rand_r(t);
  std::default_random_engine generator(t);
  std::uniform_int_distribution<int> distribution(44, 47);
  _deck.erase(_deck.begin() + distribution(generator));
}

// removes top-most card from _deck and returns a Card for adding into a
// playerHand
Card Deck::draw() {
  Card temp = _deck.back();
  _deck.pop_back();
  return temp;
}

// randomly shuffles _deck vector
void Deck::shuffleDeck() {
  time_t t;
  srand(time(&t));
  int rand_r(t);
  shuffle(std::begin(_deck), std::end(_deck), std::default_random_engine(t));
}

// returns the value of the vector _deck.size()
int Deck::size() {
  return _deck.size();
}

// prints out a list of the cards contained in the deck
void Deck::printDeck() {
  for (size_t i = 0; i < size(); i++)
    std::cout << _deck[i] << '\n';
}
