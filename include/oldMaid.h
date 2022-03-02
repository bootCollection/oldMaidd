/**
* @author Elliot Etches
* @date 2020, 2020-09
*/

// this is the header for the declaration of the oldMaid class
#ifndef OLDMAID_H
#define OLDMAID_H
#include <iostream>
#include <string>
#include "../include/playerHand.h"

class oldMaid {
 public:
    /////////////////////////////////
    //Constructors and destructors//
    /**
    * -Deafult constructor
    */
    oldMaid();

    /**
    * -Deafult destructor
    */
    ~oldMaid();

    //////////////////////////////////
    //Game set up and gameplay loop//
    /**
    * player
    * - Initializes names
    * - Discards queen
    * - Shuffles deck
    * - Deals cards
    * - Begins gameplay loop:
    * -- Player selects pair
    * -- Ai selects pair
    * -- Player selects single card
    * -- AI selects single card
    * - Ends loop when only one queen remains and no other card
    */
    void play();

 private:
  //Game rule enforcement//
   /**
   * deal
   * -Shuffles Deck
   * -Deals cards to each player one at a time
   * -Prints cards each time a card is delet
   * -Waits for user prompt before ending
   */
    void deal();

    /**
    * queenCheck
    * -Checks if only one card remains
    * -If this is true, determines which player has only one card
    * -Outputs the name of this player
    */
    bool queenCheck();

    /**
    * pairSelect
    * - Outputs prompt for pair selection
    * - Gets input from player
    * - Sorts through input for two integers using findPair
    * - Verifies the validity of input
    * - If valid, removes pairs
    * - Outputs removed pairs
    * - Waits for user prompt before continuing
    * - If help is entered, help function is called
    * - If done is entered, pair selection closes
    */
    void pairSelect();

    /**
    * singleSelect
    * - Outputs prompts for pair selection
    * - Recieves user inPut
    * - Verifies the validity of input
    * - Removes valid inputs from target and gives to player
    * - Outputs selections
    * - Waits for user prompt before closing
    * - If help is entered, calls help function
    */
    void singleSelect();

    //CI operations//
    /**
    * ciPairSelect
    * @param P The playerHand class which the operation shoudl be ran once
    * @param name The name which should be attatched to Outputs
    * - Scans through AI hand and removes all pairs
    * - Outputs AI choice
    * - Waits for user prompt before continuing
    */
    void ciPairSelect(PlayerHand* P, std::string name);

    /**
    * ciSingleFL
    * @param flip Enters the current flip flop state into function
    * @param taker The hand which should be selecing
    * @param giver The hand which is being selected from
    * @returns the oposite of the bool value entered for flip
    * - If true is entered, selects first value
    * - Waits for user prompt before continueing
    * - If false is entered, selects last value
    * - Waits for user prompt before continueing
    */
    bool ciSingleFL(bool flip, PlayerHand* taker, PlayerHand* giver);

    /**
    * ciSingleRan
    * - Selects a random card from giver
    * - Gives this card to taker
    * - Ouputs AI decision
    * - Waits for user prompt before continueing
    */
    void ciSingleRan(PlayerHand* taker, PlayerHand* giver);
    //Input functions//
    /**
    * findPair
    * @param in The input string which is serached for integers
    * @param s1 The first integer found
    * @param s2 The second integer found
    * @returns True if pair found, false otherwise
    * - Located integers within a string
    * - Verifies the validity of those integers
    */
    bool findPair(std::string in, int* s1, int* s2);

    /**
    * checkInt
    * @param in The input string
    * @param s The integer located within the string
    * @returns True if a valid integer is found, false otherwise
    * - Locates an integer within a string
    * - Verifies the validity of that integer
    */
    bool findSingle(std::string in, int* s);
    /**
    * @param in The input string to be searched
    * @param word The word which is searched for
    * @returns True if the given word is found, false otherwise
    * -Searches a given string for a given word
    */
    bool findWord(std::string in, std::string word);
    /**
    * checkInt
    * @param in The given string to be checked
    * @returns True if the string is an integer, false otherwise
    * - Verifies if a given string is an integer
    */
    bool checkInt(std::string in);
    //Output functions//
    /**
    * gameHelp
    * - Outputs a help screen for Old Maid
    * - Waits for user prompt before closing
    */
    void gameHelp();
    /**
    * showTable
    * @param selector allows for selection of output type
    * -selector = 0 : Outputs entire table
    * -selector = 1 : Outputs third player hand
    * -selector = 2 : Outputs the second player hand
    * -selector = 3 : Outputs the first player hand
    */
    void showTable(int selector);
    /**
    * @param name1 The first name selected
    * @param name2 The second name selected
    * - Randomly selects a name from a given list
    * - Verifies that identical names are not selected
    */
    void nameSelect(std::string* name1, std::string* name2);
    //Private variables//
    Deck _playingDeck;
    PlayerHand _P1;
    PlayerHand _P2;
    PlayerHand _P3;
    std::string _name1;
    std::string _name2;
};
#endif
