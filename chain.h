#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <type_traits>

#include "gemstones.h"
#include "cardfactory.h"

using std::string;
using std::vector;
using std::endl;
using std::istringstream;

#ifndef CHAIN_H
#define CHAIN_H

class Chain_Base {

public:
	friend std::ostream& operator<<(std::ostream& outputStream, const Chain_Base& chainBase);
	virtual int sell();
	virtual Chain_Base& operator+=(Card* card);

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
	inline Chain(std::istream& inputStream, CardFactory* cardFactory) {

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
				*this += card;
			}
		}
	};

	inline Chain<T>& operator+=(Card* card) {

		//downcast
		Quartz* quartzCard = dynamic_cast<Quartz*>(card);
		Hematite* hematiteCard = dynamic_cast<Hematite*>(card);
		Obsidian* obsidianCard = dynamic_cast<Obsidian*>(card);
		Malachite* malachiteCard = dynamic_cast<Malachite*>(card);
		Turquoise* turquoiseCard = dynamic_cast<Turquoise*>(card);
		Ruby* rubyCard = dynamic_cast<Ruby*>(card);
		Amethyst* amethystCard = dynamic_cast<Amethyst*>(card);
		Emerald* emeraldCard = dynamic_cast<Emerald*>(card);

		//nullptr means ivalid cast
		if(quartzCard != nullptr) {
			if(std::is_same<T, Quartz>::value) {
				chainVector.push_back(quartzCard);
				return *this;
			}
		}else if(hematiteCard != nullptr) {
			if(std::is_same<T, Hematite>::value) {
				chainVector.push_back(hematiteCard);
				return *this;
			}
		}else if(obsidianCard != nullptr) {
			if(std::is_same<T, Obsidian>::value) {
				chainVector.push_back(obsidianCard);
				return *this;
			}
		}else if(malachiteCard != nullptr) {
			if(std::is_same<T, Malachite>::value) {
				chainVector.push_back(malachiteCard);
				return *this;
			}
		}else if(turquoiseCard != nullptr) {
			if(std::is_same<T, Turquoise>::value) {
				chainVector.push_back(turquoiseCard);
				return *this;
			}
		}else if(rubyCard != nullptr) {
			if(std::is_same<T, Ruby>::value) {
				chainVector.push_back(rubyCard);
				return *this;
			}
		}else if(amethystCard != nullptr) {
			if(std::is_same<T, Amethyst>::value) {
				chainVector.push_back(amethystCard);
				return *this;
			}
		}else if(emeraldCard != nullptr) {
			if(std::is_same<T, Emerald>::value) {
				chainVector.push_back(emeraldCard);
				return *this;
			}
		}

		throw IllegalTypeException();
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
