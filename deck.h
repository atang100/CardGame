#include <vector>
#include <string>

#include "card.h";

using std::string;
using std::vector;

class Deck : public vector<Card> {

public:
	Deck(std::istream&, CardFactory*);

	// returns and removes the card at the top of the deck
	Card* draw();
};