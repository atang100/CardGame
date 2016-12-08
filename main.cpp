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
using std::ofstream;

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
		ifstream inFile;
		inFile.open("save_data.txt");

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
			std::ofstream ofs;
			ofs.open("save_data.txt", std::ofstream::out | std::ofstream::trunc); //clear text file
			table->print(ofs);
			ofs.close();
		}
		else //actual game logic
		{
			Player** players = table->getPlayers();

			for(int i=0;i<2;i++)
			{
				Player* player = players[i];

				cout << "***** " << player->getName() << "'s turn" << " *****" << endl;

				table->print(cout); //print table, maybe add another method to make this look nicer

				//can buy a chain if they have 3 coins and 2 chains
				if(player->getNumCoins() >= 3 && player->getNumChains() == 2)
				{
					string purchase;
					cout << "Purchase another chain (y/n): ";

					if (purchase == "y")
					{
						player->buyThirdChain();
					}
				}else{
					cout << "Not enough money to buy a chain, skipping." << endl;
				}

				cout << "Drawing card from deck" << endl;
				player->addCardToHand(table->drawCardFromDeck()); //draw from deck and add card to hand


				TradeArea* tradeArea = table->getTradeArea();
				DiscardPile* discardPile = table->getDiscardPile();

				cout << "Moving cards from trade area to chains." << endl;
				if (tradeArea->numCards() > 0) //if trade area not empty
				{
					for(int chainIndex;chainIndex<player->getNumChains();chainIndex++) { //for each chain type
						string chainType = (*player)[chainIndex].getChainType();

						Card* card = nullptr;

						do{
							card = tradeArea->trade(chainType); //take all cards of that type from the trade area
							try{
								if(card != nullptr) {
									((*player)[chainIndex]) += card; //and add to the chain
								}
							}catch(exception& e){} //shouldnt happen since we chain type before adding to chain, put it here anyways

						}while(card != nullptr);
					}

					//discard all remaining cards to the discard pile
					Card* card = nullptr;
					do{
						card = tradeArea->getTop();
						if(card != nullptr) {
							*discardPile += card; //add card to discard pile
						}
					}while(card != nullptr);
				}




				int repCount = 0;
				do {
					//play topmost card from hand
					cout << "Playing top card" << endl;
					Card* playCard = player->getHand()->play(); //get the card to play
					bool addedToChain = false;
					for(int chainIndex=0;chainIndex<player->getNumChains();chainIndex++) {
						try{
							((*player)[chainIndex]) += playCard;
							addedToChain = true;
							break;
						}catch(exception& e){}
					}


					//couldnt add to chain, so we either need to sell a chain to make room
					//or create a new chain if there is space to do so
					if(!addedToChain) {
						if(player->getNumChains() >= player->getMaxNumChains()) { //already at max number of chains, so we need to sell
							player->sellChain(*discardPile);
						}
						player->makeNewChain(playCard->getName()); //make a new chain
						(*player)[player->getNumChains()-1] += playCard; //add card to new chain
					} //TODO: if the user successfully plays the card, should they be given the option to sell the chain?

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
					cout << "Hand:  ";
					player->printHand(cout, true); //print full hand

					cout << endl;
					cout << "Index: ";
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
				cout << "Drawing 3 cards to put on trade area." << endl;
				for(int j=0;j<3;j++)
				{
					*tradeArea += table->drawCardFromDeck();
				}

				//while top discard pile card matches a card in the trade area
					//draw the top card from discard pile and put in trade area
				cout << "Adding cards from discard pile to trade area." << endl;
				while(tradeArea->legal(discardPile->top()))
				{
					*tradeArea += discardPile->pickUp();
				}



				if (tradeArea->numCards() > 0) //if trade area not empty
				{
					int maxIndex = tradeArea->numCards();

					for(int tradeAreaIndex=0; tradeAreaIndex<maxIndex;tradeAreaIndex++)
					{
						for(int chainIndex=0;chainIndex<player->getNumChains();chainIndex++)
						{
							string chainType = (*player)[chainIndex].getChainType();
							Card* peekedCard = tradeArea->peek(tradeAreaIndex);

							if(chainType == peekedCard->getName()) //card is same type as chain
							{
								cout << "Do you want to chain the card " << *peekedCard << "? (y/n): ";
								string shouldChain;
								cin >> shouldChain;

								if(shouldChain == "y") //chain if user wants to chain
								{
									(*player)[chainIndex] += tradeArea->trade(chainType);
									maxIndex--;
									tradeAreaIndex--; //adjust loop for removed card

									cout << "Do you want to sell this chain ( " << (*player)[chainIndex] << " )? (y/n): ";
									string sellChain;
									cin >> sellChain;

									if(sellChain == "y") {
										player->sellChain(chainIndex, *discardPile);
									}
								}
								break; //dont try to add to more than one chain
							}
						}
					}
				}


				cout << "Drawing two cards to player's hand." <<endl;
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
