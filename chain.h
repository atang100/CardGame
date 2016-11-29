#include <string>
#include <vector>
#include <iostream>

#include "gemstones.h"

using std::string;
using std::vector;
using std::endl;


class Chain_Base {
};


template <class T>
class Chain : public Chain_Base {

private:
	string chainCardName;
	vector<T> chainVector;

public:
	inline Chain(std::istream& istream, CardFactory* cardFactory) {

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
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	};

	inline void setCardName(string cardName) {
		chainCardName = cardName;
	};

	inline friend std::ostream& operator<<(std::ostream& outputStream, const Chain& chain) {
		outputStream << chain.chainCardName;
		outputStream << "    ";

		for(auto card : chain.chainVector) {
			outputStream << *card;
			outputStream << " ";
		}

		outputStream << endl;
	};
};
