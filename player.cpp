#include "player.h";

Player::Player(string& name)
{
	d_name = name;
	d_coins = 0;
}

Player::Player(istream& inputStream, CardFactory* cardFactory)
{

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

}

// returns number of non zero chains
int Player::getNumChains()
{

}

// returns chain at position i
Chain_Base& Player::operator[](int i)
{

}

// add an empty third chain for 2 coins
void Player::buyThirdChain()
{

}

// print the top in player's hand if false, other print entire hand
void Player::printHand(std::ostream&, bool)
{

}

ostream & operator <<(ostream &out, const Player&)
{

}