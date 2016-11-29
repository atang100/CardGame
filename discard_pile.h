#include <vector>
#include <string>
#include <iostream>

#include "card.h";

using std::string;
using std::vector;

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
	Card* top();

	//Dump all cards in the discard pile to the ostream
	void print(std::ostream&);

	inline friend ostream& operator<<(ostream& outputStream, const DiscardPile& hand) {
		outputStream << *hand.top();

		return outputStream;
	}
}
