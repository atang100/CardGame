#include <string>

using std::string;

/**
 * Base Class: Card
 * Derived Classes: Quartz, Hematite, Obsidian, Malachite, Turquoise, Ruby, Amethyst, and Emerald
 */

class Card {

public:
	// get how many cards necessary to receive "x" amount of coins.
	virtual int getCardsPerCoin(int coins);

	// returns full name of card.
	virtual string getName();

	virtual void print(std::ostream& out);
};



class Quartz : public Card {

protected:
	string name = "Quartz";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out);
};

class Hematite : public Card {

protected:
	string name = "Hematite";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out);
};

class Obsidian : public Card {

protected:
	string name = "Obsidian";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out);
};

class Malachite : public Card {

protected:
	string name = "Malachite";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out);
};

class Turquoise : public Card {

protected:
	string name = "Turquoise";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out);
};

class Ruby : public Card {

protected:
	string name = "Ruby";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out);
};

class Amethyst : public Card {

protected:
	string name = "Amethyst";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out);
};

class Emerald : public Card {

protected:
	string name = "Emerald";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out);
};