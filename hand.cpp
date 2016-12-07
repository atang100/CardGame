#include <iostream>
#include <string>
#include <sstream>

#include "hand.h"

using std::string;
using std::endl;
using std::getline;
using std::istringstream;

//Default constructor
Hand::Hand()
{

}

/*
This constructor is only used when we are reloading a saved game otherwise default
constructor can be used.
*/

Hand::Hand(std::istream& inputStream, CardFactory* cardFactory)
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
			handQueue.push(card);
		}
	}
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

int Hand::size() {
	return handQueue.size();
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


std::ostream& operator<<(std::ostream& outputStream, Hand& hand)
{
	int queueSize = hand.handQueue.size();

	for(int i=0; i<queueSize; i++)
	{
		Card* card = hand.handQueue.front();
		hand.handQueue.pop();
		outputStream << *card << " ";
		hand.handQueue.push(card);
	}

	return outputStream;
}
