#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include "deck.h"
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

void Deck::push_back(Card* card) {
	this->push_back(card);
}

void Deck::shuffle() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(this->begin(), this->end(), std::default_random_engine(seed));
}
