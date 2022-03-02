/**
* @author Eric Sotkowy <sotkowy@uleth.ca>, Spencer Taylor
* @date 2020, 2020-09
*/

// this is the header for the declaration of the PlayerHand class

#ifndef PLAYERHAND_H
#define PLAYERHAND_H
//add all required libraries. usually just iostream for .h
#include <iostream>
#include <vector>
#include "../include/card.h"
#include "../include/deck.h"

class PlayerHand {
 public:
    //constructor and delete functions
    PlayerHand();
    ~PlayerHand();
    int size();
    const Card getCard(int);
    void printHand();
    void printHandFaceDown();
    void printIndex();
    void sort();
    void push(const Card&);
    void remove(int);
    Card& operator[] (int);
 private:
    std::vector<Card> _hand;
};
  #endif
