#include "table.h"
#include "cardfactory.h";

/******************/
/*   Table        */
/******************/

Table::Table()
{
	CardFactory* cardFactory = CardFactory::getFactory();
	deck = cardFactory->getDeck;
	discardPile = new DiscardPile();

	//TODO: Replace temp names with a user entered name.
	string p1_name = "Player 1";
	string p2_name = "Player 2"; 

	player1 = new Player(p1_name);
	player2 = new Player(p2_name);
}

Table::Table(std::istream& inputStream, CardFactory* cardFactory)
{
	//deck = new Deck(inputStream, cardFactory);
}

// returns true when a player has won
bool Table::win(std::string& playerName)
{

}

// prints the complete table with all the contents
void Table::print(std::ostream& outputStream)
{

}