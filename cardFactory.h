#include "deck.h";

class CardFactory {

public:
	// returns a pointer to the only instance of CardFactory
	static CardFactory *getFactory();

	// returns a deck with all 104 gemstone cards
	Deck getDeck();
};