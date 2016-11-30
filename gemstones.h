#include <string>
#include <iostream>

using std::string;

/**
 * Base Class: Card
 * Derived Classes: Quartz, Hematite, Obsidian, Malachite, Turquoise, Ruby, Amethyst, and Emerald
 */
#ifndef GEMSTONES_H
#define GEMSTONES_H

class Card {

public:

	friend std::ostream& operator<<(std::ostream& out, const Card& card);
	// get how many cards necessary to receive "x" amount of coins.
	virtual int getCardsPerCoin(int coins) = 0;

	// returns full name of card.
	virtual string getName() = 0;

protected:
	virtual void print(std::ostream& out) const = 0;
};


inline std::ostream& operator<<(std::ostream& out, const Card& card) {
	card.print(out);
	return out;
}


class Quartz : public Card {

protected:
	string name = "Quartz";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out) const;
};

class Hematite : public Card {

protected:
	string name = "Hematite";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out) const;
};

class Obsidian : public Card {

protected:
	string name = "Obsidian";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out) const;
};

class Malachite : public Card {

protected:
	string name = "Malachite";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out) const;
};

class Turquoise : public Card {

protected:
	string name = "Turquoise";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out) const;
};

class Ruby : public Card {

protected:
	string name = "Ruby";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out) const;
};

class Amethyst : public Card {

protected:
	string name = "Amethyst";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out) const;
};

class Emerald : public Card {

protected:
	string name = "Emerald";

public:
	// get how many cards necessary to receive "x" amount of coins.
	int getCardsPerCoin(int coins);

	// returns full name of card.
	string getName();

	void print(std::ostream& out) const;
};

#endif
