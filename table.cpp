#include "table.h"
#include "cardfactory.h"
#include "discard_pile.h"
#include "trade_area.h"

/******************/
/*   Table        */
/******************/

Table::Table()
{
	CardFactory* cardFactory = CardFactory::getFactory();
	deck = cardFactory->getDeck;
	*discardPile = DiscardPile();

	//TODO: Replace temp names with a user entered name.
	string p1_name = "Player 1";
	string p2_name = "Player 2"; 

	*player1 = Player(p1_name);
	*player2 = Player(p2_name);
}

/*
Text File Format:

Line 1: Deck
Line 2: Discard Pile
Line 3: Trade Area
Line 4: Player 1 Name
Line 5: Player 1 Coin
Line 6: Player 1 Max Number Chain
Line 7: Player 1 Chain
Line 8: Player 1 Hand
Line 9: Player 2 Name
Line 10: Player 2 Coin
Line 11: Player 2 Max Number Chain
Line 12: Player 2 Chain
Line 13: Player 2 Hand

*/
Table::Table(std::istream& inputStream, CardFactory* cardFactory)
{
	*deck = Deck(inputStream, cardFactory);
	*discardPile = DiscardPile(inputStream, cardFactory);
	*tradeArea = TradeArea(inputStream, cardFactory);
	*player1 = Player(inputStream, cardFactory);
	*player2 = Player(inputStream, cardFactory);
}

// returns true when a player has won
bool Table::win(std::string& playerName)
{

}

// prints the complete table with all the contents
void Table::print(std::ostream& outputStream)
{

}