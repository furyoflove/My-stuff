#ifndef _DECK_H
#define _DECK_H

#include "card.h"
#include <stack>

using namespace std;

class Deck {

  public:

    Deck();

    void Shuffle();
    Card GetCard();

    int size();
    bool IsEmpty();

  private:

    static const int MAX = 52;

    stack<Card> cards; // current deck of cards

};

#endif
