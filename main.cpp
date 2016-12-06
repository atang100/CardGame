#include <iostream>
#include <fstream>
#include <string>

#include "table.h"
#include "cardfactory.h"
#include "deck.h"
#include "player.h"
#include "trade_area.h"

using std::string;
using std::endl;
using std::cin;
using std::cout;
using std::cerr;
using std::ifstream;

int main() {

	Table* table;

	//************ INPUT PHASE START
	cout << "Welcome to the CSI2372 Card Game" << endl;
	cout << "Please enter the number of the option you wish to select" << endl;
	cout << "1) start a new game" << endl;
	cout << "2) load from a saved game" << endl;

	string in;
	cin >> in;

	if(in == "1") { //new game

		string player1Name;
		string player2Name;

		cout << "Player 1 name: ";
		cin >> player1Name;
		cout << "Player 2 name: ";
		cin >> player2Name;

		table = new Table(player1Name, player2Name);

	}else if(in == "2") { //saved game

		string saveFileName;

		cout << "Save file name: ";
		cin >> saveFileName;

		ifstream inFile;
		inFile.open(saveFileName);

		if(!inFile) {
			cerr << "Could not open the save file!" << endl;
			return -1;
		}

		table = new Table(inFile, CardFactory::getFactory()); // pass file input stream to table constructor
	}

	//*************** END OF INPUT PHASE

	//*************** MAIN GAME LOOP

	//if table win is true, that means the deck is empty
	string winner;
	while(!table->win(winner)) {

		//first step in game loop is to check if game should be paused
		string pause;
		cout << "Pause? (y/n): ";
		cin >> pause;

		if(pause == "y") { //save logic

		}else{ //actual game logic

		}
	}

	if(winner == "") {
		cout << "Tie game!" << endl;
	}else{
		cout << winner << " won!" << endl;
	}
}
