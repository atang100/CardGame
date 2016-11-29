#include "hand.h"

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
	Card* returnCard = nullptr;

	int queueSize = handQueue.size();

	for(int i=0; i=queueSize; i++) { //loop through queue
		Card* card = handQueue.front(); //dequeue first element
		handQueue.pop();

		if(i == index) {
			returnCard = card; //at index, this is the pointer we want to return
			//if we are at the index, don't reinsert into the queue so that it is removed
		}else{
			handQueue.push(card); //if not at the index put the element back in the queue
		}
	}

	return returnCard;
}
