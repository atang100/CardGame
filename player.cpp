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
	char c[256];

	inputStream.getline(c, 256); //name
	string name(c);

	inputStream.getline(c, 256); //coin
	string s_coins(c);

	inputStream.getline(c, 256); //max chains
	string s_maxNumChains(c);

	inputStream.getline(c, 256); //current number of chains
	string s_num_chains(c);

	d_name = name;
	d_coins = atoi(s_coins.c_str());
	maxNumChains = atoi(s_maxNumChains.c_str());
	int num_chains = atoi(s_num_chains.c_str());

	//maxNumChains can take a value of 2 or 3.
	//TODO this needs to set the type of the chain as well
	//cannot create a chain of Card*
	for (int i = 0; i < num_chains; i++)
	{
		inputStream.getline(c, 256);
		string card_name(c);

		if (card_name == "Q" || card_name == "Quartz") {
			Chain<Quartz>* chain = new Chain<Quartz>(inputStream, cardFactory);
			chains.push_back(chain);
		}
		else if (card_name == "H" || card_name == "Hematite") {
			Chain<Hematite>* chain = new Chain<Hematite>(inputStream, cardFactory);
			chains.push_back(chain);
		}
		else if (card_name == "O" || card_name == "Obsidian") {
			Chain<Obsidian>* chain = new Chain<Obsidian>(inputStream, cardFactory);
			chains.push_back(chain);
		}
		else if (card_name == "M" || card_name == "Malachite") {
			Chain<Malachite>* chain = new Chain<Malachite>(inputStream, cardFactory);
			chains.push_back(chain);
		}
		else if (card_name == "T" || card_name == "Turquoise") {
			Chain<Turquoise>* chain = new Chain<Turquoise>(inputStream, cardFactory);
			chains.push_back(chain);
		}
		else if (card_name == "R" || card_name == "Ruby") {
			Chain<Ruby>* chain = new Chain<Ruby>(inputStream, cardFactory);
			chains.push_back(chain);
		}
		else if (card_name == "A" || card_name == "Amethyst") {
			Chain<Amethyst>* chain = new Chain<Amethyst>(inputStream, cardFactory);
			chains.push_back(chain);
		}
		else if (card_name == "E" || card_name == "Emerald") {
			Chain<Emerald>* chain = new Chain<Emerald>(inputStream, cardFactory);
			chains.push_back(chain);
		}
	}

	d_hand = new Hand(inputStream, cardFactory);
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
	return *this;
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

void Player::addCardToHand(Card* card) {
	*d_hand += card;
}

Hand* Player::getHand() {
	return d_hand;
}

void Player::sellChain(DiscardPile& discardPile) {
	*this += chains.back()->sell(); //sell chain
	chains.back()->moveToDiscardPile(discardPile);
	chains.pop_back();
}

void Player::makeNewChain(string type) {
	if(type == "Quartz") {
		chains.push_back(new Chain<Quartz>());
	}else if(type == "Hematite") {
		chains.push_back(new Chain<Hematite>());
	}else if(type == "Obsidian") {
		chains.push_back(new Chain<Obsidian>());
	}else if(type == "Malachite") {
		chains.push_back(new Chain<Malachite>());
	}else if(type == "Turquoise") {
		chains.push_back(new Chain<Turquoise>());
	}else if(type == "Ruby") {
		chains.push_back(new Chain<Ruby>());
	}else if(type == "Amethyst") {
		chains.push_back(new Chain<Amethyst>());
	}else if(type == "Emerald") {
		chains.push_back(new Chain<Emerald>());
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

std::ostream& operator <<(std::ostream& outputStream, const Player& player)
{
	outputStream << player.d_name << endl;
	outputStream << player.d_coins << endl;
	outputStream << player.maxNumChains << endl;
	outputStream << player.chains.size() << endl;

	for (auto chain : player.chains) {
		outputStream << *chain << endl;
	}

	outputStream << *player.d_hand;

	return outputStream;
}
