#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <type_traits>

#include "gemstones.h"
#include "cardfactory.h"
#include "discard_pile.h"

using std::string;
using std::vector;
using std::endl;
using std::istringstream;

#ifndef CHAIN_H
#define CHAIN_H

class Chain_Base {

public:
	friend std::ostream& operator<<(std::ostream& outputStream, const Chain_Base& chainBase);
	virtual int sell() = 0;
	virtual Chain_Base& operator+=(Card* card) = 0;
	virtual string getChainType() = 0;
	virtual void moveToDiscardPile(DiscardPile& discardPile) = 0;
	inline virtual ~Chain_Base() {};

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
	vector<T*> chainVector;

public:

	inline Chain() {
	};

	inline ~Chain() {
	};

	/*
	Line 1: Chain Card Name
	Line 2: List of Cards
	*/
	inline Chain(std::istream& inputStream, CardFactory* cardFactory)
	{
		char c[256];
		inputStream.getline(c, 256);
		string line(c);

		//Makes it easy to loop through line by ' ' delimiter.
		istringstream gemstone(line);

		while (gemstone)
		{
			string gemstoneName;
			gemstone >> gemstoneName;

			Card* card = cardFactory->getCard(gemstoneName);

			if(card)
			{
				*this += card;
			}
		}
	};

	inline Chain<T>& operator+=(Card* card) {
		if(dynamic_cast<T*>(card) != nullptr) {
			chainVector.push_back(dynamic_cast<T*>(card));
		}else{
			throw IllegalTypeException();
		}
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

	inline void moveToDiscardPile(DiscardPile& discardPile)
	{
		for (auto &card : chainVector) {
			discardPile += card;
		}
	};

	inline string getChainType() {
		if(std::is_same<T, Quartz>::value) {
			return "Quartz";
		}else if(std::is_same<T, Hematite>::value) {
			return "Hematite";
		}else if(std::is_same<T, Obsidian>::value) {
			return "Obsidian";
		}else if(std::is_same<T, Malachite>::value) {
			return "Malachite";
		}else if(std::is_same<T, Turquoise>::value) {
			return "Turquoise";
		}else if(std::is_same<T, Ruby>::value) {
			return "Ruby";
		}else if(std::is_same<T, Amethyst>::value) {
			return "Amethyst";
		}else if(std::is_same<T, Emerald>::value) {
			return "Emerald";
		}
	};

	inline void print(std::ostream& outputStream) const
	{
		outputStream << chainVector.front()->getName();

		for(auto card : chainVector)
		{
			outputStream << " " << *card;
		}
	}
};

#endif
