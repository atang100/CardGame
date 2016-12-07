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

	Table* table = NULL;

	//************ INPUT PHASE START
	cout << "Welcome to the CSI2372 Card Game" << endl;
	cout << "Please enter the number of the option you wish to select" << endl;
	cout << "1) start a new game" << endl;
	cout << "2) load from a saved game" << endl;

	string in;
	cin >> in;

	if (in == "1") //new game
	{

		string player1Name;
		string player2Name;

		cout << "Player 1 name: ";
		cin >> player1Name;
		cout << "Player 2 name: ";
		cin >> player2Name;

		table = new Table(player1Name, player2Name);

	}
	else if (in == "2") //saved game
	{
		string saveFileName;

		cout << "Save file name: ";
		cin >> saveFileName;

		ifstream inFile;
		inFile.open(saveFileName);

		if (!inFile)
		{
			cerr << "Could not open the save file!" << endl;
			return -1;
		}

		table = new Table(inFile, CardFactory::getFactory()); // pass file input stream to table constructor
	}

	if (table == NULL)
	{
		return -1;
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

		if(pause == "y") //save logic
		{

		}
		else //actual game logic
		{
			Player** players = table->getPlayers();

			for(int i=0;i<2;i++)
			{
				Player* player = players[i];

				table->print(cout); //print table, maybe add another method to make this look nicer

				//can buy a chain if they have 3 coins and 2 chains
				if(player->getNumCoins() >= 3 && player->getNumChains() == 2)
				{
					//player->buyThirdChain();
				}

				player->addCardToHand(table->drawCardFromDeck()); //draw from deck and add card to hand


				TradeArea* tradeArea = table->getTradeArea();
				DiscardPile* discardPile = table->getDiscardPile();

				if (tradeArea->numCards() > 0) //if trade area not empty
				{
					//add cards from trade area to chains or discard them

					list<Card*> tradeAreaCards = tradeArea->getCards();

					int tradeAreaSize = tradeArea->numCards();
					for(int j=0;j<tradeAreaSize;j++) {
						Card* currentCard = tradeAreaCards.front();
						tradeAreaCards.pop_front();

						//try to add it to the chain
						bool addedToChain = false;
						for(int chainIndex=0;chainIndex<player->getNumChains();chainIndex++) {
							try{ //if we cant add it to the chain, an exception will be thrown
								((*player)[i]) += currentCard;
								addedToChain = true;
								break; //added to chain, dont try to add to another chain
							}catch(exception& e){}
						}

						if(!addedToChain) { //if not added to chain, keep in trade area
							tradeAreaCards.push_back(currentCard);
						}
					}
				}




				int repCount = 0;
				do {
					//play topmost card from hand
					Card* playCard = player->getHand()->play(); //get the card to play
					bool addedToChain = false;
					for(int chainIndex=0;chainIndex<player->getNumChains();chainIndex++) {
						try{
							((*player)[i]) += playCard;
							addedToChain = true;
							break;
						}catch(exception& e){}
					}

					if(!addedToChain) {
						player->sellChain();
						player->makeNewChain(playCard->getName()); //TODO: add function (takes card name to know what type)
						(*player)[player->getNumChains()-1] += playCard; //add card to new chain
					}

					if(repCount == 0) {

						cout << "Do you want to play the topmost card again? (y/n): " << endl;
						string repeat;
						cin >> repeat;

						if(repeat == "n") {
							repCount++;
						}
					}

					repCount++;

				}while(repCount < 2); //repeat? y/n



				//show full hand & discard? y/n
				//***** START OF DISCARD PHASE *******
				cout << "Do you want to discard from your hand? (y/n): " << endl;
				string discard;
				cin >> discard;

				if(discard == "y")
				{
					player->printHand(cout, true); //print full hand

					int handSize = player->getHand()->size();

					for(int displayIndex=0;displayIndex<handSize;displayIndex++)
					{
						cout << displayIndex << " ";
					}
					cout << endl;

					bool has_only_digits = false;
					string index;

					while (has_only_digits == false || stoi(index) >= handSize)
					{
						cout << "Enter an index to discard: ";
						cin >> index;
						has_only_digits = (index.find_first_not_of("0123456789") == string::npos); //Makes sure user enters a number.
					}

					Card* arbitraryCard = (*player->getHand())[stoi(index)];
					*discardPile += arbitraryCard;
				}
				//**** END OF DISCARD PHASE *****
				//draw 3 cards from deck & put on trade area
				for(int j=0;j<3;j++)
				{
					*tradeArea += table->drawCardFromDeck();
				}

				//while top discard pile card matches a card in the trade area
					//draw the top card from discard pile and put in trade area
				while(tradeArea->legal(discardPile->top()))
				{
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
