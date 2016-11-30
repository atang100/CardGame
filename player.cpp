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
}

/*
Important:

Text file format:

	name
	coins
	maxNumChains
	<chain> chain1 chain2 etc
	<hand> gemstone1 gemstone2 etc
*/

Player::Player(istream& inputStream, CardFactory* cardFactory)
{
	string s_coins;
	string s_maxNumChains;

	inputStream >> d_name;
	inputStream >> s_coins;

	d_coins = atoi(s_coins.c_str());

	inputStream >> s_maxNumChains;

	s_maxNumChains = atoi(s_maxNumChains.c_str());


	/*
	2 lines should remain:

		<chain> chain1 chain2 etc
		<hand> gemstone1 gemstone2 etc
	*/

	*d_hand = Hand(inputStream, cardFactory);
	//No clue what to do with chain.
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

ostream& operator <<(ostream& out, const Player& player)
{
	out << player.d_name << endl;
	out << player.d_coins << endl;
	out << player.maxNumChains << endl;

	for(auto chain : player.chains) {
		out << *chain;
	}
}
