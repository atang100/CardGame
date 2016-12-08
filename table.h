#include <string>

#include "cardfactory.h"
#include "player.h"
#include "discard_pile.h"
#include "trade_area.h"
#include "deck.h"
#include "gemstones.h"

using std::string;
using std::ostream;
using std::istream;

#ifndef TABLE_H
#define TABLE_H

class Table {

	Player* player1;
	Player* player2;
	Player* players[2];
	DiscardPile* discardPile;
	Deck deck;
	TradeArea* tradeArea;

public:

	Table(string, string);

	Table(std::istream&, CardFactory*);

	~Table();

	//easier to loop through players as an array in main game loop
	Player** getPlayers();

	Card* drawCardFromDeck();

	TradeArea* getTradeArea();

	DiscardPile* getDiscardPile();

	// returns true when a player has won
	bool win(std::string& playerName);

	// prints the complete table with all the contents
	void print(std::ostream& outputStream);

	friend ostream & operator <<(ostream &out, const Table&);
};

#endif
