#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <string>
#include <vector>

#include "deck.h"
#include "gemstones.h"

using std::vector;

class CardFactory {

	static CardFactory* instance;
	static vector<Card*> cards;

	CardFactory() {
	}

public:
	// returns a pointer to the only instance of CardFactory
	static CardFactory* getFactory();

	// returns a deck with all 104 gemstone cards
	Deck getDeck();

	Card* getCard(string);
};

#endif
