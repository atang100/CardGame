#include <string>

#include "Chain_Base.h";
#include "hand.h";
#include "cardFactory.h";

using std::string;
using std::ostream;
using std::istream;

class Player {

protected:

	string name;
	int coins;
	Hand* hand;

public:
	
	Player(string& name);

	Player(std::istream&, CardFactory*);

	// get the name of the player
	string getName();

	// get the number of coins currently held by player
	int getNumCoins();

	// add a number of coins
	Player& operator+=(int numOfCoin);

	int getMaxNumChains();

	// returns number of non zero chains
	int getNumChains();

	// returns chain at position i
	Chain_Base& operator[](int i);

	// add an empty third chain for 2 coins
	void buyThirdChain();

	// print the top in player's hand if false, other print entire hand
	void printHand(std::ostream&, bool);

	friend ostream & operator <<(ostream &out, const Player&);
};