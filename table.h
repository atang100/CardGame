#include <string>

#include "cardFactory.h";

using std::string;
using std::ostream;
using std::istream;

class Table {

protected:

public:

	Table(std::istream&, CardFactory*);

	// returns true when a player has won
	bool win(std::string& playerName);

	// prints the complete table with all the contents
	void print(std::ostream& outputStream);

	friend ostream & operator <<(ostream &out, const Table&);
};