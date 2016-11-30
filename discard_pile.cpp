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

//This constructor is only used when we are reloading a saved game.
DiscardPile::DiscardPile(std::istream& inputStream, CardFactory* cardFactory) 
{
	/*
	Reads inputStream line by line until it finds "<DiscardPile>" which indicates
	that this line contains the list of cards in the discard pile.
	*/
	for (string line; getline(inputStream, line); ) {
		if (line.find("<DiscardPile>"))
		{
			//Makes it easy to loop through line by ' ' delimiter.
			istringstream gemstone(line);

			//First string is "<DiscardPile>" but CardFactory will return nullptr
			//so there shouldn't be an issue.
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
			break;
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

	/*
	Careful when altering this format.  <DiscardPile> is used as an identifier
	when reading through file to identify that the line contains gems that are in the
	discard pile.
	*/
	outputStream << "<DiscardPile>";
	for(auto card : discardPileVector) {
		outputStream << *card;
	}

	//Important to end line to indicate the end of the discard pile.
	outputStream << endl; 
}
