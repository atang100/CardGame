#include <vector>
#include <string>
#include <iostream>

#include "gemstones.h"
#include "cardFactory.h"

using std::string;
using std::vector;

#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

class DiscardPile {

private:
	vector<Card*> discardPileVector;

public:
	DiscardPile(std::istream&, CardFactory* );

	//Discard a card to the DiscardPile
	DiscardPile& operator+=( Card* );

	//Return & remove top card off of the DiscardPile
	Card* pickUp();

	//Return the top card off of the DiscardPile (don't remove)
	Card* top() const;

	//Dump all cards in the discard pile to the ostream
	void print(std::ostream&);

	inline friend std::ostream& operator<<(std::ostream& outputStream, const DiscardPile& discardPile) {
		outputStream << *discardPile.top();

		return outputStream;
	};
};

#endif
