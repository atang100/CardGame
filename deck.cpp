#include <algorithm>    // std::random_shuffle
#include <iostream>
#include <string>
#include <sstream>

#include "deck.h"

using std::endl;
using std::getline;
using std::istringstream;


/******************/
/*   Deck         */
/******************/

Deck::Deck() 
{

}

/*
This constructor is only used when we are reloading a saved game otherwise default
constructor can be used.
*/

Deck::Deck(std::istream& inputStream, CardFactory* cardFactory)
{
	string line;
	inputStream >> line;

	//Makes it easy to loop through line by ' ' delimiter.
	istringstream gemstone(line);

	while (gemstone)
	{
		string gemstoneName;
		gemstone >> gemstoneName;

		Card* card = cardFactory->getCard(gemstoneName);

		if (card != nullptr)
		{
			this->push_back(card);
		}
	}
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
	std::random_shuffle(this->begin(), this->end());
}
