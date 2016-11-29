#include <algorithm>    // std::random_shuffle

#include "deck.h"
#include "cardFactory.h"

/******************/
/*   Deck         */
/******************/

Deck::Deck() {

}

Deck::Deck(std::istream&, CardFactory*)
{

}

// returns and removes the card at the top of the deck
Card* Deck::draw()
{
	Card* card = this->back();
	this->pop_back();

	return card;
}

Deck::push_back(Card* card) {
	this->push_back(card);
}

Deck::shuffle() {
	std::random_shuffle(this->begin(), this->end());
}
