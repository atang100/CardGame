
/**
* Base Class: Vector
*/

#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>

#include "gemstones.h"
#include "cardfactory.h"

using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::endl;

class CardFactory; //forward declaration

class Deck : public vector<Card*> {

public:
	Deck();
	Deck(istream&, CardFactory*);

	// returns and removes the card at the top of the deck
	Card* draw();

	void push_back(Card*);

	void shuffle();

	inline friend ostream & operator <<(ostream &out, Deck& deck){
        Card* card;
        for(int i = 0; i < deck.size(); i++){
            card = deck.draw();
            out << *card << " ";
			deck.push_back(card);
        }
        return out;
    };
};

#endif
