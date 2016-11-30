#include <queue>

#include "gemstones.h"
#include "cardfactory.h"

using std::queue;

#ifndef HAND_H
#define HAND_H

class Hand {

private:
	queue<Card*> handQueue;

public:
	//Constructor
	Hand(std::istream&, CardFactory*);

	//Add card to back of hand
	Hand& operator+=(Card*);

	//Return and remove top cart from player's hand
	Card* play();

	//Return top card from player's hand (don't remove)
	Card* top();

	//Returns and removes card at index
	Card* operator[](int);

	inline friend std::ostream& operator<<(std::ostream& outputStream, Hand& hand) {

		outputStream << "<Hand> ";

		int queueSize = hand.handQueue.size();
		for(int i=0; i=queueSize; i++) {
			Card* card = hand.handQueue.front();
			hand.handQueue.pop();
			outputStream << *card << " ";
			hand.handQueue.push(card);
		}

		return outputStream;
	};
};

#endif
