#include <string>

#include "cardfactory.h"
#include "player.h"
#include "discard_pile.h"
#include "trade_area.h"
#include "deck.h"

using std::string;
using std::ostream;
using std::istream;

#ifndef TABLE_H
#define TABLE_H

class Table {

protected:

	Player* player1;
	Player* player2;
	DiscardPile* discardPile;
	Deck deck;
	TradeArea* tradeArea;

public:

	Table();

	Table(std::istream&, CardFactory*);

	// returns true when a player has won
	bool win(std::string& playerName);

	// prints the complete table with all the contents
	void print(std::ostream& outputStream);

	friend ostream & operator <<(ostream &out, const Table&);
};

#endif
