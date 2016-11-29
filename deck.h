#include <vector>
#include <string>

#include "gemstones.h"

using std::string;
using std::vector;
using std::ostream;

/**
* Base Class: Vector
*/

#ifndef DECK_H
#define DECK_H

class Deck : public vector<Card> {

public:
	Deck(std::istream&, CardFactory*);

	// returns and removes the card at the top of the deck
	Card* draw();

	inline friend ostream & operator <<(ostream &out, Deck& deck){

        //write deck to file
        out << deck.size();

        Card* card;
        for(int i = 0; i < deck.size(); i++){
            card = deck.draw();
            out << card->name;
            out << card;
        }

        return out;
    };
};

#endif
