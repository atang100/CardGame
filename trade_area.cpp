#include "trade_area.h";


TradeArea::TradeArea(std::istream&, CardFactory*)
{

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
	for (std::list<Card*>::const_iterator iterator = cards.begin(), end = cards.end(); iterator != end; ++iterator) {
		if (card == *iterator)
		{
			return true;
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
		}
	}

	//If card has been found, remove it from list.
	if (card != nullptr)
	{
		cards.remove(card);
	}

	return card;
}

// returns number of cards currently in trade area
int TradeArea::numCards()
{
	return cards.size();
}

ostream & operator <<(ostream &out, const TradeArea&)
{

}