/**
* @author Elliot Etches, Spencer Taylor
* @date 2020, 2020-09
*/
#include "oldMaid.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <random>

//constructor function
oldMaid :: oldMaid() {
}

//destructor class
oldMaid :: ~oldMaid() {
}
void oldMaid :: play() {
  bool flipFlop = true;
  nameSelect(&(_name1), &(_name2));
  deal();
  pairSelect();
  //Gameplay loop
  while ( !queenCheck() ) {
    //First AI pair selection
    ciPairSelect(&(_P2), _name1);
    //Second AI pair selection
    ciPairSelect(&(_P3), _name2);
    //Human player single card selection from _P2
    singleSelect();
    pairSelect();
    if (queenCheck())
      break;
    //First AI single card selection from _P3
    flipFlop = ciSingleFL(flipFlop, &(_P2), &(_P3));
    ciPairSelect(&(_P2), _name1);
    if (queenCheck())
      break;
    //Second AI single card selection from _P1
    ciSingleRan(&(_P3), &(_P1));
    ciPairSelect(&(_P3), _name2);
    if (queenCheck())
      break;
  }
}
//Deal function
//Shuffles deck and distributes cards
//Displays those cards
void oldMaid :: deal() {
  _playingDeck.shuffleDeck();
  //Loop to hand out card, then display table
  do {
    _P1.push(_playingDeck.draw());
    showTable(0);
    _P2.push(_playingDeck.draw());
    showTable(0);
    _P3.push(_playingDeck.draw());
    showTable(0);
  } while (_playingDeck.size() != 0);
  //User prompt to continue
  std::cout << "~|Deck has been delt|~" << std::endl << std::endl;
  std::cout << "Press <Enter> to Continue";
  std::cin.ignore();
}
//queenCheck
//Verifies that the game hasn't reached an end state
//If an endstate is reached, declares the loser
bool oldMaid :: queenCheck() {
  //Checking if only one card remains
  if (_P1.size() + _P2.size() + _P3.size() == 1) {
    std::cout << std::endl;
    //Declaring the loser
    if (_P1.size() == 1)
      std::cout << "You are the old maid!" << std::endl;
    if (_P2.size() == 1)
      std::cout << _name1 << " is the Old Maid!" << std::endl;
    if (_P3.size() == 1)
      std::cout << _name2 << " is the Old Maid!" << std::endl;
    return true;
  }
  return false;
}
//pairSelect
//Input function which tries to locate two integers in a string
void oldMaid :: pairSelect() {
  //Input loop flag
  bool flag = true;
  int s1, s2;
  std::string inPut;
  //Input loop
  while (flag) {
    showTable(3);
    //Prompt pLayer for string
    std::cout << "++|Selecting pairs|++" << std::endl << std::endl;
    std::cout << "~|For help, type \"Help\"|~" << std::endl;
    std::cout << "~|When you are finished selecting pairs type \"Done\"|~"
    << std::endl << std::endl;
    std::cout << ">> Select pair \"a b\": " << std::endl;
    std::cout << ">> ";
    //Input string
    std::getline(std::cin, inPut);
    //Calls findPair helper function to locate two integers
    if (findPair(inPut, &(s1), &(s2))) {
      //Check if selected indexes have matching ranks
      if (_P1[s1].getRank() == _P1[s2].getRank()) {
        //Remove matching pair
        _P1.remove(s1);
        _P1.remove(s2 - 1);
        //User feedback
        showTable(0);
        std::cout << "++|You have removed a pair at "
                  << "(" << s1 + 1 << ", " << s2 + 1 << ")|++" << std::endl
                  << std::endl;
        std::cout << "Press <Enter> to Continue";
        std::cin.ignore();
      }
    } else if (findWord(inPut, "HELP")) {
        gameHelp();
      } else if (findWord(inPut, "DONE")) {
          flag = false;
        }
  }
}
//singleSelect
//Used to get a single integer from player
void oldMaid :: singleSelect() {
  if (_P2.size() != 0) {
    //Input loop flag
    bool flag = true;
    int s;
    std::string inPut;
    //Input loop
    while (flag) {
      showTable(2);
      //Input prompt
      std::cout << "-+|Selecting card from " << _name1 << "|+-" << std::endl
      << std::endl;
      std::cout << "~|For help, type \"Help\"|~" << std::endl << std::endl;
      std::cout << ">> Select single card \"a\": " << std::endl;
      std::cout << ">> ";
      //Input string
      std::getline(std::cin, inPut);
      //Find single
      if (findSingle(inPut, &(s))) {
        //Swap cards
        _P1.push(_P2[s]);
        _P2.remove(s);
        //User feedback
        showTable(0);
        std::cout << "++|You have chosen " << _name1 << "'s card at (" << s + 1
                  << ")|++" << std::endl << std::endl;
        std::cout << ">> Press <Enter> to Continue";
        std::cin.ignore();
        flag = false;
      } else if (findWord(inPut, "HELP")) {
          gameHelp();
      } else if (findWord(inPut, "DONE")) {
          flag = false;
        }
    }
  }
}
//ciPairSelect
//AI pair selection
void oldMaid :: ciPairSelect(PlayerHand* P, std::string name) {
  //Search array for pairings
  if (P->size() != 1) {
    for (int i = 0; i < P->size(); i++)
      for (int j = i + 1; j < P -> size(); j++)
        if ((P -> getCard(i)).getRank() == (P -> getCard(j)).getRank()) {
          P -> remove(j);
          P -> remove(i);
          showTable(0);
          //User feedback
          std::cout << "++|" << name << " removed pair at "
                    << "(" << i << ", " << j << ")|++" << std::endl
                    << std::endl;
          std::cout << ">> Press <Enter> to Continue";
          std::cin.ignore();
        }
  }
}
//ciSingleFL
//Flip flop function to pick cards
bool oldMaid :: ciSingleFL(bool flip, PlayerHand* taker, PlayerHand* giver) {
  //Check that the player you're picking from has cards
  if (giver -> size() == 0)
    return flip;
  //Select first card
  if (flip) {
    taker -> push(giver -> getCard(0));
    giver -> remove(0);
    //User feedback
    showTable(0);
    std::cout << "-+|" << _name1 << " chooses " << _name2 << "\'s card at "
              << "(" << "1" << ")|+-" << std::endl;
    std::cout << "Press <Enter> to Continue";
    std::cin.ignore();;
    return false;
  //Select last card
  } else {
      taker -> push(giver -> getCard(giver -> size() - 1));
      giver -> remove(giver -> size() - 1);
      //User feedback
      showTable(0);
      std::cout << "-+|" << _name1 << " chooses " << _name2 << "\'s card at "
              << "(" << giver -> size() << ")|+-" << std::endl << std::endl;
      std::cout << "Press <Enter> to Continue";
      std::cin.ignore();
      return true;
    }
}
//ciSingleRan
//Selects a random card
void oldMaid :: ciSingleRan(PlayerHand* taker, PlayerHand* giver) {
  //Check that there are cards to take
  if (giver -> size() != 0) {
    //Select random value
    time_t t;
    srand(time(&t));
    int rand_r(t);
    std::default_random_engine generator(t);
    int index = generator() % giver -> size();
    //Swap card
    taker -> push(giver -> getCard(index));
    giver -> remove(index);
    //User feedback
    showTable(0);
    std::cout << "-+|" << _name2 << " chooses your card at "
              << "(" << index + 1 << ")|+-" << std::endl << std::endl;
    std::cout << "Press <Enter> to Continue";
    std::cin.ignore();;
  }
}
//Find pair
//Determines if two integers exist in a string
//Verifies that those integers are valid selections
bool oldMaid :: findPair(std::string in, int* s1, int* s2) {
  int counter = 0;
  int intList[3];
  std::string temp;
  std::stringstream ssInput;
  ssInput << in;
  while (!ssInput.eof()) {
    ssInput >> temp;
    if (std::stringstream(temp) >> temp) {
      if (checkInt(temp)) {
        intList[counter] = stoi(temp);
        counter++;
      }
    }
    if (counter == 3)
      return false;
  }
  if (counter != 2)
    return false;
  if (intList[0] < 1 || intList[1] < 1)
    return false;
  if (intList[0] > _P1.size() + 1 || intList[1] > _P1.size() + 1)
    return false;
  *(s1) = intList[0] - 1;
  *(s2) = intList[1] - 1;
  return true;
}
bool oldMaid :: findSingle(std::string in, int* s) {
  int counter = 0;
  int intList[2];
  std::string temp;
  std::stringstream ssInput;
  ssInput << in;
  while (!ssInput.eof()) {
    ssInput >> temp;
    if (std::stringstream(temp) >> temp) {
      if (checkInt(temp)) {
        intList[counter] = stoi(temp);
        counter++;
      }
    }
    if (counter == 2)
      return false;
  }
  if (counter != 1)
    return false;
  if (intList[0] < 1)
    return false;
  if (intList[0] > _P2.size())
    return false;
  *(s) = intList[0] - 1;
  return true;
}
//findWord
//Determines if a given word is located within a string
bool oldMaid :: findWord(std::string in, std::string word) {
  std::string temp;
  std::stringstream ssInput;
  ssInput << in;
  while (!ssInput.eof()) {
    ssInput >> temp;
    if (std::stringstream(temp) >> temp) {
      //Transforms temp string into to uppercase
      std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
      if (temp.compare (word) == 0)
        return true;
    }
  }
  return false;
}
//checkInt
//determines if a given string is a valid integer
bool oldMaid :: checkInt(std::string in) {
  char* c;
  strtol(in.c_str(), &c, 10);
  return(*c == 0);
}
//Help function
void oldMaid :: gameHelp() {
  if (system("CLS")) system("clear");
  std::cout << std::setfill(' ') << std::setw(28) << "-=| Help |=-"
            << std::endl << std::endl;
  std::cout << std::setfill(' ') << std::setw(10) << " "
            << "-+| The Story So Far |+-"
            << std::endl;
  std::cout << "With the economy in recession and debts pilling up" << std::endl
  << "it is only natural to go into debt. Unfortunately, " << std::endl
  << "you have found yourself in the red with a notorious group" << std::endl
  << "of Russian expats. The bills cannot be paid, " << std::endl
  << "and a risky venture must be employed before the Russians" << std::endl
  << "foreclose on your kneecaps." << std::endl << std::endl
  << "Armed with a deck of "
  << "playing cards, and confident in your gambling ability, " << std::endl
  << "you march into the dive bar which serves as their " << std::endl
  << "local branch to put it all on the line. Your joy at " << std::endl
  << "their acceptance of the offer is quickly replaced with " <<std::endl
  << "shock upon realising that it is not poker nor blackjack " << std::endl
  << "you will be playing. Instead the Russians have chosen " << std::endl
  << "the childrens card game of Old Maid." << std::endl << std::endl;
  std::cout << std::setfill(' ') << std::setw(14) << " " << "-+| The Game |+-"
            << std::endl;
  std::cout << "Old maid is quite a simple game. A single queen" << std::endl
  << "is removed from the deck before it is shuffled, thereby" << std::endl
  << "leaving and odd number of queens." << std::endl << std::endl
  << _name1 << " sits to your right, " << _name2 << " to your left."
  << std::endl
  << "The cards will be partitioned out  the shuffled deck" << std::endl
  << "one at a time. You will then discard any pairs of matching" << std::endl
  << "ranks (The 1, 2, Queen, King, ...) you possess." << std::endl
  << "After this is complete you will turn to " << _name1 << std::endl
  << "and pick one of his cards which he will present to you" << std::endl
  << "face down. Then, " << _name2 << " will pick from you in the" << std::endl
  << "same manner as before." << std::endl << std::endl
  << "This will be repeated until only one unmatchable card" << std::endl
  << "remains, the lone Queen, or \"Old Maid\"." << std::endl
  << "Whoever holds the Old Maid at the end is the loser." << std::endl
  << std::endl;
  std::cout << "Press <Enter> to exit at any time."
            << std::endl << std::endl;
  std::cin.ignore();
}
//showTable
//Prints out the table, or different hands depending on the selector
void oldMaid :: showTable(int selector) {
  if (system("CLS")) system("clear");
  if (selector == 1 || selector == 0) {
    std::cout << std::setfill('=') << std::setw(38 - _name1.size()) << "|"
              << _name2 << "|"
              << std::setw(38 - _name2.size()) << "=" << std::endl;
    if (_P3.size() != 0) {
      _P3.printHandFaceDown();
    } else {
        for (int i = 0; i < 6; i++)
          std::cout << "\\" << std::endl;
      }
  std::cout << std::endl;
}
  if (selector == 2 || selector == 0) {
    std::cout << std::setfill('=') << std::setw(38- _name1.size()) << "|"
    << _name1 << "|"  << std::setw(38 - _name1.size()) << "=" << std::endl;
    if (selector != 0)
      _P2.printIndex();
    if (_P2.size() != 0) {
      _P2.printHandFaceDown();
    } else {
        for (int i = 0; i < 6; i++)
          std::cout << "\\" << std::endl;
    }
  std::cout << std::endl;
  }
  if (selector == 3 || selector == 0) {
    std::cout << std::setfill('=') << std::setw(38) << "|You|"
              << std::setw(35) << "=" << std::endl;
    if (selector != 0)
      _P1.printIndex();
    if (_P1.size() != 0) {
      _P1.printHand();
    } else {
        for (int i = 0; i < 6; i++)
          std::cout << "\\" << std::endl;
      }
  std::cout << std::endl;
  }
}
//Name select
//chooses a random name for the AI players
void oldMaid :: nameSelect(std::string* name1, std::string* name2) {
  std::string nameList[6] = {"Dima", "Ivan", "Nikita", "Vlad",
  "Sergey", "Dasha"};
  //Random value generator
  time_t t;
  srand(time(&t));
  int rand_r(t);
  std::default_random_engine generator(t);
  int index = generator() % 5;
  //Name selection
  *(name1) = nameList[index];
  index = generator() % 5;
  *(name2) = nameList[index];
  //Ensures that duplicate names are not selected
  if (*(name1) == *(name2) && index != 5)
    *(name2) = nameList[index + 1];
  else if (*(name1) == *(name2))
    *(name2) = nameList[index - 1];
}
