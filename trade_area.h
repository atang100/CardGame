#include <string>
#include <list>

#include "cardfactory.h"
#include "gemstones.h"

using std::string;
using std::ostream;
using std::istream;
using std::list;

#ifndef TRADE_AREA_H
#define TRADE_AREA_H

class TradeArea {

protected:

	list<Card*> cards;

public:

	TradeArea();

	TradeArea(std::istream&, CardFactory*);

	// adds the card to the trade area
	TradeArea& operator+=(Card* card);

	// returns true if card can be legally added to trade area
	bool legal(Card* card);

	// removes a card corresponding to gemstone name from trade area
	Card* trade(string name);

	//removes a card from the trade area for discarding
	Card* getTop();

	//returns a pointer to the card at a particular index
	Card* peek(int);

	// returns number of cards currently in trade area
	int numCards();

	inline friend ostream& operator <<(ostream &out, const TradeArea& tradeArea)
	{
		for (auto card : tradeArea.cards) {
			out << *card << " ";
		}
		return out;
	}

};

#endif
