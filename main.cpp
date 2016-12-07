#include <iostream>
#include <fstream>
#include <string>

#include "table.h"
#include "cardfactory.h"
#include "deck.h"
#include "player.h"
#include "trade_area.h"

using std::string;
using std::endl;
using std::cin;
using std::cout;
using std::cerr;
using std::ifstream;

int main() {

	Table* table;

	//************ INPUT PHASE START
	cout << "Welcome to the CSI2372 Card Game" << endl;
	cout << "Please enter the number of the option you wish to select" << endl;
	cout << "1) start a new game" << endl;
	cout << "2) load from a saved game" << endl;

	string in;
	cin >> in;

	if(in == "1") { //new game

		string player1Name;
		string player2Name;

		cout << "Player 1 name: ";
		cin >> player1Name;
		cout << "Player 2 name: ";
		cin >> player2Name;

		table = new Table(player1Name, player2Name);

	}else if(in == "2") { //saved game

		string saveFileName;

		cout << "Save file name: ";
		cin >> saveFileName;

		ifstream inFile;
		inFile.open(saveFileName);

		if(!inFile) {
			cerr << "Could not open the save file!" << endl;
			return -1;
		}

		table = new Table(inFile, CardFactory::getFactory()); // pass file input stream to table constructor
	}

	//*************** END OF INPUT PHASE

	//*************** MAIN GAME LOOP

	//if table win is true, that means the deck is empty
	string winner;
	while(!table->win(winner)) {

		//first step in game loop is to check if game should be paused
		string pause;
		cout << "Pause? (y/n): ";
		cin >> pause;

		if(pause == "y") { //save logic

		}else{ //actual game logic
			Player** players = table->getPlayers();
			for(int i=0;i<2;i++) {
				Player* player = players[i];

				table->print(cout); //print table, maybe add another method to make this look nicer

				//can buy a chain if they have 3 coins and 2 chains
				if(player->getNumCoins() >= 3 && player->getNumChains() == 2) {
					//player->buyThirdChain();
				}

				player->addCardToHand(table->drawCardFromDeck()); //draw from deck and add card to hand


				TradeArea* tradeArea = table->getTradeArea();
				DiscardPile* discardPile = table->getDiscardPile();


				if(tradeArea->numCards() > 0) { //if trade area not empty
					//add cards from trade area to chains or discard them

					/* FIX THIS TOO
					list<Card*> tradeAreaCards = tradeArea->getCards();

					int tradeAreaSize = tradeArea->numCards();
					for(int j=0;j<tradeAreaSize;j++) {
						Card* currentCard = tradeArea->;

						for(auto chain : player->getChains()) {
							try{ //if we cant add it to the chain, an exception will be thrown
								*chain += currentCard;
							}catch(exception& e){}
						}
					}

					*/
				}

				//play topmost card from hand

				//if end chain, delete chain, and give goins

				//repeat? y/n

				//show full hand & discard? y/n
				//***** START OF DISCARD PHASE *******
				cout << "Do you want to discard from your hand? (y/n): " << endl;
				string discard;
				cin >> discard;

				if(discard == "y") {
					player->printHand(cout, true); //print full hand

					int handSize = player->getHand()->size();

					for(int displayIndex=0;displayIndex<handSize;displayIndex++) {
						cout << displayIndex << " ";
					}
					cout << endl;

					cout << "Enter an index to discard: ";
					string index;
					cin >> index;

					while(stoi(index) >= handSize) {
						cout << "Enter an index to discard: ";
						string index;
						cin >> index;
					}

					Card* arbitraryCard = (*player->getHand())[stoi(index)];
					*discardPile += arbitraryCard;
				}
				//**** END OF DISCARD PHASE *****

				//draw 3 cards from deck & put on trade area
				for(int j=0;j<3;j++) {
					*tradeArea += table->drawCardFromDeck();
				}

				//while top discard pile card matches a card in the trade area
					//draw the top card from discard pile and put in trade area
				while(tradeArea->legal(discardPile->top())) {
					*tradeArea += discardPile->pickUp();
				}


				//NEEDS TO BE FIXED
				/*
				//for all cards in trade area
				list<Card*> tradeAreaCards = tradeArea->getCards();
				int numTradeAreaCards = tradeArea->numCards();

				for(int tradeCardIndex=0;tradeCardIndex<numTradeAreaCards;tradeCardIndex++) {
					Card* tradeAreaCard = tradeAreaCards[tradeCardIndex];

					cout << "Do you want to chain this card? (y/n): ";
					string chain;
					cin >> chain;

					if(chain == "y") {
						//chain here


						cout << "Want to sell the chain? (y/n): ";
						string endChain;
						cin >> endChain;

						if(endChain == "y") {
							//sell and delete chain
						}
					}
				}
				*/

				//draw 2 from deck, add to player's hand
				player->addCardToHand(table->drawCardFromDeck()); //draw from deck and add card to hand
				player->addCardToHand(table->drawCardFromDeck()); //draw from deck and add card to hand
			}
		}
	}

	if(winner == "") {
		cout << "Tie game!" << endl;
	}else{
		cout << winner << " won!" << endl;
	}
}
