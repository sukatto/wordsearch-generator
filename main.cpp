#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

	// generates seed for randomizer
	srand(time(NULL));

	// gets number of words
	cout << "\nPlease enter the number of words in the word search: ";
	int numWords = 0;
	cin >> numWords;
	// checks to make sure input was an integer
	while (cin.fail()) {
		cout << "That is not an integer.  Please enter an integer for the number of words: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> numWords;
	}
	cin.ignore();
	cout << "\n";

	// pointer to array of words that stores the words entered by user
	string * words = new string[numWords];

	// gets each word from user
	for (int cnt = 0; cnt < numWords; cnt++) {
		cout << "Please enter word #" << (cnt + 1) << ": ";
		string newStr = "";
		getline(cin, newStr);
		*(words + cnt) = newStr;
	}

	// generates initial grid
	char * grid[25];
	for (int cnt = 0; cnt < 25; cnt++) {
		grid[cnt] = new char[25];
	}

	// initializes grid
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			*((grid[i]) + j) = '?';
		}
	}

	// inserts each word into grid
	for (int cnt = 0; cnt < numWords; cnt++) {
		bool inGrid = false;
		string word = *(words + cnt);
		while (!inGrid) {
			// random row, column, and orientation are set
			int ranRow = rand() % 25;	
			int ranCol = rand() % 25;
			int ranOr = rand() % 8 + 1;
			// checks to see if word will fit based on orientation
			if (ranOr == 1) {if (word.length() > (25 - ranCol)) {continue;};};
			if (ranOr == 2) {if (word.length() > (25 - ranRow)) {continue;};};
			if (ranOr == 3) {if (word.length() > (ranCol + 1)) {continue;};};
			if (ranOr == 4) {if (word.length() > (ranRow + 1)) {continue;};};
			if (ranOr == 5) {if ((word.length() > (25 - ranRow)) || (word.length() > (25 - ranCol))) {continue;};};
			if (ranOr == 6) {if ((word.length() > (25 - ranRow)) || (word.length() > (ranCol + 1))) {continue;};};
			if (ranOr == 7) {if ((word.length() > (ranRow + 1)) || (word.length() > (25 - ranCol))) {continue;};};
			if (ranOr == 8) {if ((word.length() > (ranRow + 1)) || (word.length() > (ranCol + 1))) {continue;};};
			// variables for row and column increment coefficients, which will determine how the loops that go through each letter of the word traverse the grid, are set
			int rowInCoef = 0;
			int colInCoef = 0;
			if (ranOr == 1) {
					rowInCoef = 0;
					colInCoef = 1;
			};
			if (ranOr == 2) {
					rowInCoef = 1;
					colInCoef = 0;
			};
			if (ranOr == 3) {
					rowInCoef = 0;
					colInCoef = -1;
			};
			if (ranOr == 4) {
					rowInCoef = -1;
					colInCoef = 0;
			};
			if (ranOr == 5) {
					rowInCoef = 1;
					colInCoef = 1;
			};
			if (ranOr == 6) {
					rowInCoef = 1;
					colInCoef = -1;
			};
			if (ranOr == 7) {
					rowInCoef = -1;
					colInCoef = 1;
			};
			if (ranOr == 8) {
					rowInCoef = -1;
					colInCoef = -1;
			};
			// checks to see if word can be placed based in the randomly-generated spot based on what's already on the grid; if it can't then the row, column, and orientation are re-randomized and the test for insertion repeats
			bool canFit = true;
			for (int k = 0; k < word.length(); k++) {
				if ((*((grid[ranRow + (rowInCoef * k)]) + ranCol + (colInCoef * k)) != '?') && (*((grid[ranRow + (rowInCoef * k)]) + ranCol + (colInCoef * k)) != word[k])) {
					canFit = false;
					break;
				}
			}
			if (!canFit) {continue;};
			// at this point the word is confirmed to fit and not overwrite any existing letters on the grid, thus it is placed on the grid, and the main loop continues on to insert the next word, if there is one
			for (int k = 0; k < word.length(); k++) {
				*((grid[ranRow + (rowInCoef * k)]) + ranCol + (colInCoef * k)) = word[k];
			}
			inGrid = true;
	
		}
	}

	// fills in the rest of the grid with random letters
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (*((grid[i]) + j) == '?') {
				*(grid[i] + j) = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
			}
		}
	}

	cout << "\n";
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			cout << *((grid[i]) + j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	// displays all words on bottom to search for
	cout << "KEY:\n";
	int wordsOnLine = 0;
	for (int cnt = 0; cnt < numWords; cnt++) {
		if (wordsOnLine < 5)
			cout << *(words + cnt) << "\t";
		else {
			wordsOnLine = 0;
			cout << "\n" << *(words + cnt) << "\t";
		}
		wordsOnLine++;
	}
	cout << "\n\n";

	return 0;
}
