#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

	// generates seed for randomizer
	srand(time(NULL));

	// gets number of words
	cout << "\n";
	cout << "Please enter the number of words in the word search: ";
	int numWords = 0;
	cin >> numWords;
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

	for (int cnt = 0; cnt < numWords; cnt++) {
		bool inGrid = false;
		string word = *(words + cnt);
		while (!inGrid) {
			int ranRow = rand() % 25;	
			int ranCol = rand() % 25;
			int ranOr = rand() % 8 + 1;
			bool canFit = true;
			if (ranOr == 1) {
				if (word.length() > (25 - ranCol)) {
					canFit = false;
				}
				if (canFit) {
					for (int k = 0; k < word.length(); k++) {
						if ((*((grid[ranRow]) + ranCol + k) != '?') && (*((grid[ranRow]) + ranCol + k) != word[k])) {
							canFit = false;
						}
					}
					if (canFit) {
						for (int k = 0; k < word.length(); k++) {
							*((grid[ranRow]) + ranCol + k) = word[k];
							inGrid = true;
						}
					}
				}
			}
			else if (ranOr == 2) {
				if (word.length() > (25 - ranRow)) {
					canFit = false;
				}
				if (canFit) {
					for (int k = 0; k < word.length(); k++) {
						if ((*((grid[ranRow + k]) + ranCol) != '?') && (*((grid[ranRow + k]) + ranCol) != word[k])) {
							canFit = false;
						}
					}
					if (canFit) {
						for (int k = 0; k < word.length(); k++) {
							*((grid[ranRow + k]) + ranCol) = word[k];
							inGrid = true;
						}
					}
				}
			}
			else if (ranOr == 3) {
				if (word.length() > (ranCol + 1)) {
					canFit = false;
				}
				if (canFit) {
					for (int k = 0; k < word.length(); k++) {
						if ((*((grid[ranRow]) + ranCol - k) != '?') && (*((grid[ranRow]) + ranCol - k) != word[k])) {
							canFit = false;
						}
					}
					if (canFit) {
						for (int k = 0; k < word.length(); k++) {
							*((grid[ranRow]) + ranCol - k) = word[k];
							inGrid = true;
						}
					}
				}
			}
			else if (ranOr == 4) {
				if (word.length() > (ranRow + 1)) {
					canFit = false;
				}
				if (canFit) {
					for (int k = 0; k < word.length(); k++) {
						if ((*((grid[ranRow - k]) + ranCol) != '?') && (*((grid[ranRow - k]) + ranCol) != word[k])) {
							canFit = false;
						}
					}
					if (canFit) {
						for (int k = 0; k < word.length(); k++) {
							*((grid[ranRow - k]) + ranCol) = word[k];
							inGrid = true;
						}
					}
				}
			}
			else if (ranOr == 5) {
				if ((word.length() > (25 - ranRow)) || (word.length() > (25 - ranCol))) {
					canFit = false;
				}
				if (canFit) {
					for (int k = 0; k < word.length(); k++) {
						if ((*((grid[ranRow + k]) + ranCol + k) != '?') && (*((grid[ranRow + k]) + ranCol + k) != word[k])) {
							canFit = false;
						}
					}
					if (canFit) {
						for (int k = 0; k < word.length(); k++) {
							*((grid[ranRow + k]) + ranCol + k) = word[k];
							inGrid = true;
						}
					}
				}
			}
			else if (ranOr == 6) {
				if ((word.length() > (25 - ranRow)) || (word.length() > (ranCol + 1))) {
					canFit = false;
				}
				if (canFit) {
					for (int k = 0; k < word.length(); k++) {
						if ((*((grid[ranRow + k]) + ranCol - k) != '?') && (*((grid[ranRow + k]) + ranCol - k) != word[k])) {
							canFit = false;
						}
					}
					if (canFit) {
						for (int k = 0; k < word.length(); k++) {
							*((grid[ranRow + k]) + ranCol - k) = word[k];
							inGrid = true;
						}
					}
				}
			}
			else if (ranOr == 7) {
				if ((word.length() > (ranRow + 1)) || (word.length() > (25 - ranCol))) {
					canFit = false;
				}
				if (canFit) {
					for (int k = 0; k < word.length(); k++) {
						if ((*((grid[ranRow - k]) + ranCol + k) != '?') && (*((grid[ranRow - k]) + ranCol + k) != word[k])) {
							canFit = false;
						}
					}
					if (canFit) {
						for (int k = 0; k < word.length(); k++) {
							*((grid[ranRow - k]) + ranCol + k) = word[k];
							inGrid = true;
						}
					}
				}
			}
			else if (ranOr == 8) {
				if ((word.length() > (ranRow + 1)) || (word.length() > (ranCol + 1))) {
					canFit = false;
				}
				if (canFit) {
					for (int k = 0; k < word.length(); k++) {
						if ((*((grid[ranRow - k]) + ranCol - k) != '?') && (*((grid[ranRow - k]) + ranCol - k) != word[k])) {
							canFit = false;
						}
					}
					if (canFit) {
						for (int k = 0; k < word.length(); k++) {
							*((grid[ranRow - k]) + ranCol - k) = word[k];
							inGrid = true;
						}
					}
				}
			}
		}
	}


	cout << "\n";

	string atoz = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (*((grid[i]) + j) == '?') {
				*(grid[i] + j) = atoz[rand() % 26];
			}
		}
	}

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			cout << *((grid[i]) + j);
		}
		cout << "\n";
	}

	cout << "\n";

	return 0;
}
