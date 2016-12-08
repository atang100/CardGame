#include <algorithm>    // std::random_shuffle
#include <iostream>
#include <sstream>

#include "deck.h"

using std::getline;
using std::istringstream;


/******************/
/*   Deck         */
/******************/

Deck::Deck()
{
	//No implementation needed.
}

/*
This constructor is only used when we are reloading a saved game otherwise default
constructor can be used.
*/

Deck::Deck(istream& inputStream, CardFactory* cardFactory)
{
	char c[256];
	inputStream.getline(c, 256);
	string line(c);

	if (!line.empty())
	{
		//Makes it easy to loop through line by ' ' delimiter.
		istringstream gemstone(line);

		while (gemstone)
		{
			string gemstoneName;
			gemstone >> gemstoneName;

			Card* card = cardFactory->getCard(gemstoneName);

			if (card)
			{
				this->push_back(card);
			}
		}
	}
}

// returns and removes the card at the top of the deck
Card* Deck::draw()
{
	Card* card = nullptr;
	if(this->size() > 0) {
		card = this->back();
		this->pop_back();
	}
	return card;
}

void Deck::push_back(Card* card) {
	vector<Card*>::push_back(card);
}

void Deck::shuffle() {
	std::random_shuffle(this->begin(), this->end());
}

ostream& operator <<(ostream &out, const Deck& deck) {
	Card* card;
	for(int i = 0; i < deck.size(); i++){
			card = deck[i];
			out << *card << " ";
	}
	return out;
}
