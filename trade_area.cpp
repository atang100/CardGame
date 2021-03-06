#include <iostream>
#include <string>
#include <sstream>

#include "trade_area.h"

using std::string;
using std::endl;
using std::getline;
using std::istringstream;

/******************/
/*   TradeArea    */
/******************/

TradeArea::TradeArea()
{

}

TradeArea::TradeArea(std::istream& inputStream, CardFactory* cardFactory)
{
	char c[256];
	inputStream.getline(c, 256);
	string line(c);

	if (!line.empty())
	{
		//Makes it easy to loop through line by ' ' delimiter.
		istringstream gemstone(line);

		while (gemstone)
		{
			string gemstoneName;
			gemstone >> gemstoneName;

			Card* card = cardFactory->getCard(gemstoneName);

			if (card)
			{
				cards.push_back(card);
			}
		}
	}
}

// adds the card to the trade area
TradeArea& TradeArea::operator+=(Card* card)
{
	cards.push_back(card);
	return *this;
}

// returns true if card can be legally added to trade area
bool TradeArea::legal(Card* card)
{
	if(card != nullptr) {
		for (std::list<Card*>::const_iterator iterator = cards.begin(), end = cards.end(); iterator != end; ++iterator) {
			if (card->getName() == (*iterator)->getName())
			{
				return true;
			}
		}
	}
	return false;
}

// removes a card corresponding to gemstone name from trade area
Card* TradeArea::trade(string name)
{
	Card* card = nullptr;

	//Iterate through list to find gemstone.
	for (std::list<Card*>::const_iterator iterator = cards.begin(), end = cards.end(); iterator != end; ++iterator) {
		if ((*iterator)->getName() == name)
		{
			card = *iterator;
			break;
		}
	}

	//If card has been found, remove it from list.
	if (card != nullptr)
	{
		cards.remove(card);
	}

	return card;
}

//pop card and return
Card* TradeArea::getTop() {
	Card* card = nullptr;
	if(cards.size() > 0) {
		card = cards.front();
		cards.pop_front();
	}
	return card;
}

Card* TradeArea::peek(int i) {
	Card* card = nullptr;

	if(cards.size() > 0 && i < cards.size()) {
		std::list<Card*>::iterator it = cards.begin();
		std::advance(it, i);
		card = *it;
	}
	return card;
}

// returns number of cards currently in trade area
int TradeArea::numCards()
{
	return cards.size();
}
