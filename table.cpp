#include "table.h"
#include "cardfactory.h"
#include "discard_pile.h"
#include "trade_area.h"

/******************/
/*   Table        */
/******************/


//This constructor is called only when starting a new game
Table::Table(string player1Name, string player2Name)
{
	CardFactory* cardFactory = CardFactory::getFactory();

	deck = cardFactory->getDeck(); //generate a deck
	deck.shuffle(); //shuffle deck

	discardPile = new DiscardPile();

	tradeArea = new TradeArea();

	player1 = new Player(player1Name);
	player2 = new Player(player2Name);

	players[0] = player1;
	players[1] = player2;

	for(int i=0;i<5;i++) { //each player draws 5 cards to start
		Card* drawnCard = deck.draw(); //draw then add to player 1 hand
		player1->addCardToHand(drawnCard);
		drawnCard = deck.draw(); //draw then add to player 2 hand
		player2->addCardToHand(drawnCard);
	}
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
	deck = Deck(inputStream, cardFactory);
	*discardPile = DiscardPile(inputStream, cardFactory);
	*tradeArea = TradeArea(inputStream, cardFactory);
	*player1 = Player(inputStream, cardFactory);
	*player2 = Player(inputStream, cardFactory);
	players[0] = player1;
	players[1] = player2;
}


Player** Table::getPlayers() {
	return players;
}


Card* Table::drawCardFromDeck() {
	return deck.draw();
}

TradeArea* Table::getTradeArea() {
	return tradeArea;
}

DiscardPile* Table::getDiscardPile() {
	return discardPile;
}

// returns true when a player has won
bool Table::win(std::string& playerName)
{
	if(deck.empty()) {

		int player1Coins = player1->getNumCoins();
		int player2Coins = player2->getNumCoins();

		if(player1Coins > player2Coins) {
			playerName = player1->getName();
		}else if(player2Coins > player1Coins) {
			playerName = player2->getName();
		}else{
			playerName = ""; //tie case
		}

		return true;
	}

	return false;
}

// prints the complete table with all the contents
void Table::print(std::ostream& outputStream)
{
	outputStream << deck << endl; //print deck
	discardPile->print(outputStream); //print discard pile
	outputStream << *tradeArea << endl; //print trade area
	outputStream << *player1 << endl; //print player 1
	outputStream << *player2 << endl; //print player 2
}
