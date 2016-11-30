#include <iostream>
#include <string>
#include <sstream>

#include "player.h"

using std::string;
using std::endl;
using std::getline;
using std::istringstream;

Player::Player(string& name)
{
	d_name = name;
	d_coins = 0;
	d_hand = new Hand();
}

/*
Text File Format:

Line 1: Name
Line 2: Coins
Line 3: Max Number of Chains
Line 4: Chain (Occupies more than 4 or 6 lines depending on "maxNumChains")
Line 5: Hand
*/

Player::Player(istream& inputStream, CardFactory* cardFactory)
{
	string s_coins;
	string s_maxNumChains;

	inputStream >> d_name;
	inputStream >> s_coins;

	d_coins = atoi(s_coins.c_str());

	inputStream >> s_maxNumChains;

	maxNumChains = atoi(s_maxNumChains.c_str());


	//maxNumChains can take a value of 2 or 3. 
	for (int i = 0; i < maxNumChains; i++)
	{
		Chain<Card*>* chain = new Chain<Card*>(inputStream, cardFactory);
		chains.push_back(chain);
	}

	*d_hand = Hand(inputStream, cardFactory);
}

// get the name of the player
string Player::getName()
{
	return d_name;
}

// get the number of coins currently held by player
int Player::getNumCoins()
{
	return d_coins;
}

// add a number of coins
Player& Player::operator+=(int numOfCoins)
{
	d_coins += numOfCoins;
}

int Player::getMaxNumChains()
{
	return maxNumChains;
}

// returns number of non zero chains
int Player::getNumChains()
{
	return chains.size();
}

// returns chain at position i
Chain_Base& Player::operator[](int i)
{
	return *chains[i];
}

// add an empty third chain for 2 coins
void Player::buyThirdChain()
{
	if(d_coins >= 2) {
		maxNumChains = 3;
		d_coins -= 2;
	}
}

// print the top in player's hand if false, other print entire hand
void Player::printHand(std::ostream& out, bool printFullHand)
{
	if(printFullHand) {
		out << *d_hand;
	}else{
		out << *d_hand->top();
	}
}