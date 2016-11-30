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
	*tradeArea = TradeArea();

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
-------------------------------------------- <-- Line does not actually exist.
Line 4: Player 1 Name
Line 5: Player 1 Coin
Line 6: Player 1 Max Number Chain
Line 7.1: Player 1 Chain Name
Line 7.2: Player 1 Chain
(Will repeat 2 or 3 times depending on Max Chain Number)
Line 8: Player 1 Hand
-------------------------------------------- <-- Line does not actually exist.
Line 9: Player 2 Name
Line 10: Player 2 Coin
Line 11: Player 2 Max Number Chain
Line 12.1: Player 1 Chain Name
Line 12.2: Player 2 Chain
(Will repeat 2 or 3 times depending on Max Chain Number)
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
	outputStream << *deck << endl; //print deck
	discardPile->print(outputStream); //print discard pile
	outputStream << *tradeArea << endl; //print trade area
	outputStream << *player1 << endl; //print player 1
	outputStream << *player2 << endl; //print player 2
}