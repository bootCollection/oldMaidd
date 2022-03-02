/**
* @author Eric Sotkowy <sotkowy@uleth.ca>, Spencer Taylor
* @date 2020, 2020-09
*/

// this is the header for the declaration of the Card class

#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
 public:
    Card();
    ~Card();
    Card(const int&, const int&);
    int getRank() const;
    int getSuit() const;

    bool operator == (const Card&) const;
    bool operator > (const Card&) const;
    bool operator < (const Card&) const;
    friend std::ostream& operator << (std::ostream&, const Card&);
 private:
    int _rank;
    int _suit;
};

#endif
