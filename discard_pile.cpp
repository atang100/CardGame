#include <iostream>
#include <string>

#include "DiscardPile.h";

using std::string;


/******************/
/*   DiscardPile  */
/******************/

DiscardPile::DiscardPile(std::istream& inputStream, CardFactory* cardFactory) {

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
Card* DiscardPile::top() {
	if(!discardPileVector.empty()) {
		return discardPileVector.back();
	}
	return nullptr;
}

//Dump all cards in the discard pile to the ostream
void DiscardPile::print(std::ostream& outputStream) {
	for(auto card : discardPileVector) {
		outputStream << *card;
	}
}
