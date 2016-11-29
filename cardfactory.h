#include "deck.h"

#ifndef CARDFACTORY_H
#define CARDFACTORY_H

class CardFactory {

public:
	// returns a pointer to the only instance of CardFactory
	static CardFactory *getFactory();

	// returns a deck with all 104 gemstone cards
	Deck getDeck();
};

#endif
