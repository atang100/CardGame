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

	Hand();

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

	friend std::ostream& operator<<(std::ostream& outputStream, Hand& hand);
};

#endif
