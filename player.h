#include <string>

#include "chain.h"
#include "hand.h"
#include "cardfactory.h"
#include "discard_pile.h"

using std::string;
using std::ostream;
using std::istream;
using std::endl;

#ifndef PLAYER_H
#define PLAYER_H

class Player {

protected:

	string d_name;
	int d_coins;
	Hand* d_hand;
	int maxNumChains = 2;
	vector<Chain_Base*> chains;

public:

	Player(string& name);

	Player(std::istream&, CardFactory*);

	~Player();

	// get the name of the player
	string getName();

	// get the number of coins currently held by player
	int getNumCoins();

	// add a number of coins
	Player& operator+=(int numOfCoins);

	int getMaxNumChains();

	// returns number of non zero chains
	int getNumChains();

	// returns chain at position i
	Chain_Base& operator[](int i);

	// add an empty third chain for 2 coins
	void buyThirdChain();

	//added this to facilitate adding a card to the players Hand
	//for example, after they draw a card from the deck
	void addCardToHand(Card*);

	//need to get hand for discarding purposes
	Hand* getHand();

	void sellChain(DiscardPile& discardPile);

	void sellChain(int, DiscardPile&);

	void makeNewChain(string);

	// print the top in player's hand if false, other print entire hand
	void printHand(std::ostream&, bool);

	//print player but make it nice to read (useful for main loop)
	void prettyPrint(std::ostream&);

	friend ostream & operator <<(ostream& outputStream, const Player& player);
};

#endif
