#include <string>
#include <vector>
#include <iostream>

#include "gemstones.h"
#include "cardfactory.h"

using std::string;
using std::vector;
using std::endl;

#ifndef CHAIN_H
#define CHAIN_H

class Chain_Base {

public:
	friend std::ostream& operator<<(std::ostream& outputStream, const Chain_Base& chainBase);

protected:
	virtual void print(std::ostream& out) const = 0;
};

inline std::ostream& operator<<(std::ostream& outputStream, const Chain_Base& chainBase) {
	chainBase.print(outputStream);
	return outputStream;
};

template <class T>
class Chain : public Chain_Base {

private:
	string chainCardName;
	vector<T*> chainVector;

public:

	/*
	Line 1: Chain Card Name
	Line 2: List of Cards
	*/
	inline Chain(std::istream& istream, CardFactory* cardFactory) {

		inputStream >> chainCardName;

		string line;
		inputStream >> line;

		//Makes it easy to loop through line by ' ' delimiter.
		istringstream gemstone(line);

		while (gemstone)
		{
			string gemstoneName;
			gemstone >> gemstoneName;

			Card* card = cardFactory->getCard(gemstoneName);

			if (card != nullptr)
			{
				chainVector.push_back(card);
			}
		}
	};

	inline Chain<T>& operator+=(Card* card) {
		chainVector.push_back(card);
	};

	inline int sell() {
		int numCards = chainVector.size();

		if(numCards > 0 ) {
			Card* card = chainVector.front();
			int coins = 0;
			bool canSell = false;
			bool canIncrementCoins = false;

			do {
				coins++;
				int cardsPerCurrentCoinVal = card->getCardsPerCoin(coins);
				canSell = (cardsPerCurrentCoinVal != -1) && (numCards >= cardsPerCurrentCoinVal || canSell);
				int cardsPerNextCoinVal = card->getCardsPerCoin(coins+1);
				canIncrementCoins = (cardsPerNextCoinVal != -1) && (numCards >= cardsPerNextCoinVal);
			}while(canIncrementCoins);

			if(canSell) {
				return coins;
			}
		}
		return 0;
	};

	inline void setCardName(string cardName) {
		chainCardName = cardName;
	};

	inline void print(std::ostream& outputStream) const 
	{
		outputStream << chainCardName << endl;

		for(auto card : chainVector) 
		{
			outputStream << *card << " ";
		}

		outputStream << endl;
	}
};

#endif
