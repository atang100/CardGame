#include "gemstones.h";

/******************/
/*   Quartz       */
/******************/

// get how many cards necessary to receive "x" amount of coins.
int Quartz::getCardsPerCoin(int coins)
{
	switch (coins)
	{
		case 1: return 4;
		case 2: return 6;
		case 3: return 8;
		case 4: return 10;
		default : return -1;
	}
}

// returns full name of card.
string Quartz::getName()
{
	return name;
}

void Quartz::print(std::ostream& out)
{
	out << "Q";
}

/******************/
/*   Hematite     */
/******************/

// get how many cards necessary to receive "x" amount of coins.
int Hematite::getCardsPerCoin(int coins)
{
	switch (coins)
	{
		case 1: return 3;
		case 2: return 6;
		case 3: return 8;
		case 4: return 9;
		default: return -1;
	}
}

// returns full name of card.
string Hematite::getName()
{
	return name;
}

void Hematite::print(std::ostream& out)
{
	out << "H";
}

/******************/
/*   Obsidian     */
/******************/

// get how many cards necessary to receive "x" amount of coins.
int Obsidian::getCardsPerCoin(int coins)
{
	switch (coins)
	{
		case 1: return 3;
		case 2: return 5;
		case 3: return 7;
		case 4: return 8;
		default: return -1;
	}
}

// returns full name of card.
string Obsidian::getName()
{
	return name;
}

void Obsidian::print(std::ostream& out)
{
	out << "O";
}

/******************/
/*   Malachite    */
/******************/

// get how many cards necessary to receive "x" amount of coins.
int Malachite::getCardsPerCoin(int coins)
{
	switch (coins)
	{
		case 1: return 3;
		case 2: return 5;
		case 3: return 6;
		case 4: return 7;
		default: return -1;
	}
}

// returns full name of card.
string Malachite::getName()
{
	return name;
}

void Malachite::print(std::ostream& out)
{
	out << "M";
}

/******************/
/*   Turquoise    */
/******************/

// get how many cards necessary to receive "x" amount of coins.
int Turquoise::getCardsPerCoin(int coins)
{
	switch (coins)
	{
		case 1: return 2;
		case 2: return 4;
		case 3: return 6;
		case 4: return 7;
		default: return -1;
	}
}

// returns full name of card.
string Turquoise::getName()
{
	return name;
}

void Turquoise::print(std::ostream& out)
{
	out << "T";
}

/******************/
/*   Ruby         */
/******************/

// get how many cards necessary to receive "x" amount of coins.
int Ruby::getCardsPerCoin(int coins)
{
	switch (coins)
	{
		case 1: return 2;
		case 2: return 4;
		case 3: return 5;
		case 4: return 6;
		default: return -1;
	}
}

// returns full name of card.
string Ruby::getName()
{
	return name;
}

void Ruby::print(std::ostream& out)
{
	out << "R";
}

/******************/
/*   Amethyst     */
/******************/

// get how many cards necessary to receive "x" amount of coins.
int Amethyst::getCardsPerCoin(int coins)
{
	switch (coins)
	{
		case 1: return 2;
		case 2: return 3;
		case 3: return 4;
		case 4: return 5;
		default: return -1;
	}
}

// returns full name of card.
string Amethyst::getName()
{
	return name;
}

void Amethyst::print(std::ostream& out)
{
	out << "A";
}

/******************/
/*   Emerald       */
/******************/

// get how many cards necessary to receive "x" amount of coins.
int Emerald::getCardsPerCoin(int coins)
{
	switch (coins)
	{
		case 2: return 2;
		case 3: return 3;
		default: return -1;
	}
}

// returns full name of card.
string Emerald::getName()
{
	return name;
}

void Emerald::print(std::ostream& out)
{
	out << "E";
}
