#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*
string suit_string(int i) {
	if (i == 0) return "spades";
	if (i == 1) return "clubs";
	if (i == 2) return "diamonds";
	if (i == 3) return "hearts";
	else {
		cout << "invalid suit (" << i << ')' << endl;
		exit(1);
	}
}
*/

class Card{
	private: 
		int face = 0;
		int suit = 0;
		string suit_string(int i) {
			if (i == 0) return "spades";
			if (i == 1) return "clubs";
			if (i == 2) return "diamonds";
			if (i == 3) return "hearts";
			else {
				cout << "invalid suit (" << i << ')' << endl;
				exit(1);
			}
		}

		string face_string(int i) {
			if (i <= 0 || i > 13) {
				cout << "invalid face (" << i << ')' << endl;
				exit(1);
			} else if (i == 1) { return "ace"; }
			else if (i == 11) { return "jack"; }
			else if (i == 12) { return "queen"; }
			else if (i == 13) { return "king"; }
			else return to_string(i);
		}
	public:
		//constructors
		Card(int face, int suit) {
			this->face = face;
			this->suit = suit;
		}
		//accessors
		int get_face() { return face; }
		string get_suit() { return suit_string(suit); }
};

void f(Card c) {
	cout << "q\n";
}


std::ostream& operator<<(std::ostream &outs, Card c) {
	string s = to_string(c.get_face()) + ", " + c.get_suit();
	outs << s;
	return outs;
}

class Deck{
	private:
		vector<Card> vec;
	public:
		//constructors
		Deck() {
			for (int i = 0; i < 13; i++) {
				for (int j = 0; j < 4; j++) {
					Card c(i + 1, j);
					vec.push_back(c);
				}
			}
		}
		//accessors
		Card get_card(int i) { return this->vec.at(i); }

};

