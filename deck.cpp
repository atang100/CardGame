#include "deck.h";
#include "cardFactory.h"

/******************/
/*   Deck         */
/******************/

Deck::Deck(std::istream&, CardFactory*)
{

}

// returns and removes the card at the top of the deck
Card* Deck::draw()
{
	Card* card = &this->back();
	this->pop_back();

	return card;
}
