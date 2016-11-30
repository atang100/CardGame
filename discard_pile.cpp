#include <iostream>
#include <string>
#include <sstream>

#include "discard_pile.h"

using std::string;
using std::endl;
using std::getline;
using std::istringstream;

/******************/
/*   DiscardPile  */
/******************/

//Default constructor.
DiscardPile::DiscardPile()
{

}

/*
This constructor is only used when we are reloading a saved game otherwise default
constructor can be used.
*/

DiscardPile::DiscardPile(std::istream& inputStream, CardFactory* cardFactory) 
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
			discardPileVector.push_back(card);
		}
	}
}

//Discard a card to the DiscardPile
DiscardPile& DiscardPile::operator+=( Card* card) {
	discardPileVector.push_back(card);
	return *this;
}

//Return & remove top card off of the DiscardPile
Card* DiscardPile::pickUp() {
	if(!discardPileVector.empty()) {
		Card* topCard = discardPileVector.back();
		discardPileVector.pop_back();
		return topCard;
	}
	return nullptr;
}

//Return the top card off of the DiscardPile (don't remove)
Card* DiscardPile::top() const {
	if(!discardPileVector.empty()) {
		return discardPileVector.back();
	}
	return nullptr;
}

//Dump all cards in the discard pile to the ostream
void DiscardPile::print(std::ostream& outputStream) {

	for(auto card : discardPileVector) {
		outputStream << *card << " ";
	}

	//Important to end line to indicate the end of the discard pile.
	outputStream << endl; 
}
