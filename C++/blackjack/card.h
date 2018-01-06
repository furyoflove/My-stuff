#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <cstring>

using namespace std;

class Card {

  public:

    enum Suit {spades, hearts, diamonds, clubs};

    Card(); // empty constructor
    Card(int _rank, Suit _suit); // full constructor

    // accessors
    int GetRank(); // return rank  1 to 13
    string GetSuit(); // return 'spades', 'hearts', 'diamonds', 'clubs'

    // primary functionality
    bool SameSuitAs(const Card &other); // return true if current is the same suit as other (target)
    string toString(); // return string version of current card

  private:

    int rank;
    Suit suit;

};

#endif
