
/**
* Base Class: Vector
*/

#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>

#include "gemstones.h"
#include "cardfactory.h"

using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::endl;

class CardFactory; //forward declaration

class Deck : public vector<Card*> {

public:
	Deck();
	Deck(istream&, CardFactory*);

	// returns and removes the card at the top of the deck
	Card* draw();

	void push_back(Card*);

	void shuffle();

	friend ostream& operator <<(ostream &out, const Deck& deck);
};

#endif
