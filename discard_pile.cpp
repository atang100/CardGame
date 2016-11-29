#include "DiscardPile.h";

/******************/
/*   DiscardPile  */
/******************/

DiscardPile::DiscardPile(std::istream& inputStream, CardFactory* cardFactory) {

}

//Discard a card to the DiscardPile
DiscardPile& DiscardPile::operator+=( Card* card) {
	push_back(card);
	return *this;
}

//Return & remove top card off of the DiscardPile
Card* DiscardPile::pickUp() {
	if(size() > 0) {
		Card* topCard = back();
		pop_back();
		return topCard;
	}
	return nullptr;
}

//Return the top card off of the DiscardPile (don't remove)
Card* DiscardPile::top() {
	if(size() > 0) {
		return back();
	}
	return nullptr;
}

//Dump all cards in the discard pile to the ostream
void DiscardPile::print(std::ostream&) {

}
