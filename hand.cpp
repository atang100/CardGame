#include "hand.h";
#include "card.h";

//Constructor
Hand::Hand(std::istream&, CardFactory*) {

}

//Add card to back of hand
Hand& Hand::operator+=(Card* card) {
	handQueue.push(card);
	return *this;
}

//Return and remove top cart from player's hand
Card* Hand::play() {
	if(!handQueue.empty()) {
		Card* card = handQueue.front(); //get top card in player's hand
		handQueue.pop(); //pop it off
		return card;
	}
	return nullptr;
}

//Return top card from player's hand (don't remove)
Card* Hand::top() {
	if(!handQueue.empty()) {
		return handQueue.front();
	}
	return nullptr;
}

//Returns and removes card at index
Card* Hand::operator[](int index) {
	if(!handQueue.empty() && handQueue.size() > index) {
		Card* card = handQueue[index]; //get card pointer
		handQueue.erase(handQueue.begin()+index); //erase card from queue
		return card;
	}
	return nullptr;
}
