#include "deck.h"
#include "card.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main(void) {

  Deck deck;
  deck.Shuffle();

  Card card = deck.GetCard();

  cout << card.toString() << endl;

} // End of main
