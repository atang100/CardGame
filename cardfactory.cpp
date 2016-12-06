#include "cardfactory.h"

CardFactory* CardFactory::instance;
vector<Card*> CardFactory::cards;

CardFactory* CardFactory::getFactory() {

	if(instance == nullptr) {
		instance = new CardFactory();
	}

	return instance;
}

//generate a new deck
Deck CardFactory::getDeck() {

	Deck deck;

	for(int i=0;i<20;i++) {
		Card* card = new Quartz();
		deck.push_back(card);
		cards.push_back(card);
	}

	for(int i=0;i<18;i++) {
		Card* card = new Hematite();
		deck.push_back(card);
		cards.push_back(card);
	}

	for(int i=0;i<16;i++) {
		Card* card = new Obsidian();
		deck.push_back(card);
		cards.push_back(card);
	}

	for(int i=0;i<14;i++) {
		Card* card = new Malachite();
		deck.push_back(card);
		cards.push_back(card);
	}

	for(int i=0;i<12;i++) {
		Card* card = new Turquoise();
		deck.push_back(card);
		cards.push_back(card);
	}

	for(int i=0;i<10;i++) {
		Card* card = new Ruby();
		deck.push_back(card);
		cards.push_back(card);
	}

	for(int i=0;i<8;i++) {
		Card* card = new Amethyst();
		deck.push_back(card);
		cards.push_back(card);
	}

	for(int i=0;i<6;i++) {
		Card* card = new Emerald();
		deck.push_back(card);
		cards.push_back(card);
	}

	printf("CardFactory: returning deck");
	fflush(stdout);
	return deck;
}

Card* CardFactory::getCard(string type) {
	Card* card = nullptr;

	if(type == "Q" || type == "Quartz") {
		card = new Quartz();
	}else if(type == "H" || type == "Hematite") {
		card = new Hematite();
	}else if(type == "O" || type == "Obsidian") {
		card = new Obsidian();
	}else if(type == "M" || type == "Malachite") {
		card = new Malachite();
	}else if(type == "T" || type == "Turquoise") {
		card = new Turquoise();
	}else if(type == "R" || type == "Ruby") {
		card = new Ruby();
	}else if(type == "A" || type == "Amethyst") {
		card = new Amethyst();
	}else if(type == "E" || type == "Emerald") {
		card = new Emerald();
	}

	cards.push_back(card); //add the card to the list of cards

	return card;
}
