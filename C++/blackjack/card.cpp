#include "card.h"

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

Card::Card() {

  // if no arguments are passed then the default deck is the single card
  // the ace of spades...
  rank = 1;
  suit  = Card::spades;

} // Empty constructor

Card::Card(int _rank, Suit _suit) {

  if(1 <= _rank && _rank <= 13) {
    rank = _rank;
  }
  else {
    cerr << "Entered rank is out of range [1,13] ";
  }

  if(_suit == spades || _suit == hearts || _suit == diamonds || _suit == clubs) {
    suit = _suit;
  }
  else {
    cerr << "Entered suit is not allowed. [spades, hearts, diamonds, clubs] ";
  }

} // full constructor

int Card::GetRank() {

  return rank;

} // Rank accessor

string Card::GetSuit() {

  if(suit == spades) {
    return "Spades";
  }
  else if(suit == hearts) {
    return "Hearts";
  }
  else if(suit == diamonds) {
    return "Diamonds";
  }
  else { // suit is clubs
    return "Clubs";
  }

} // Suit accessor

bool Card::SameSuitAs(const Card &other) {

  return suit == other.suit;

} // Find if suit matches target card

string Card::toString() {

  stringstream ss; // used for string building

  switch(rank) {
    case 1: ss << "Ace of ";
      break;
    case 2: ss << "Two of ";
      break;
    case 3: ss << "Three of ";
      break;
    case 4: ss << "Four of ";
      break;
    case 5: ss << "Five of ";
      break;
    case 6: ss << "Six of ";
      break;
    case 7: ss << "Seven of ";
      break;
    case 8: ss << "Eight of ";
      break;
    case 9: ss << "Nine of ";
      break;
    case 10: ss << "Ten of ";
      break;
    case 11: ss << "Jack of ";
      break;
    case 12: ss << "Queen of ";
      break;
    case 13: ss << "King of ";
      break;
    default: cerr << "Error: Bad Card Value ";
      return ""; // return nothing in case of error

  } // End of switch-case

  ss << GetSuit();

  return ss.str();

} // End of Card to string
