#include "deck.h"
#include "card.h"

#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

Deck::Deck() {

  int suit; // to be used to generate suits for cards

  // offset by one because indexing starts at 1 to fit in the range of acceptable ranks
  for(int rank = 1; rank < MAX/4 + 1; rank++) {
    for(suit = Card::spades; suit <= Card::clubs; suit++) {
        cards.push(Card(rank, Card::Suit(suit)));
    }
  }

} // Constructor


void Deck::Shuffle() {

  /*
    Easier to use a cheesy array temp
    Convert stack to an array to be used in random sorting
  */

  Card temp[MAX];

  for(int i = 0; i < MAX; i ++) {

    temp[i] = cards.top();
    cards.pop();

  }

  // used to set the seed
  srand(unsigned(time(0)));
  int seed = rand();

  // shuffle with a randomly generated seed
  shuffle(std::begin(temp), std::end(temp), default_random_engine(seed));

  for(int j = 0; j < MAX; j++) {
    cards.push(temp[j]);
  }

} // deck shuffling

Card Deck::GetCard() {

  Card card;

  if(!cards.empty()) {

    card = cards.top();
    cards.pop();

  }

  return card;

} // deal the top card

int Deck::size() {

  return cards.size();

} // current deck count

bool Deck::IsEmpty() {

  return cards.empty();

} // Check is deck is empty
