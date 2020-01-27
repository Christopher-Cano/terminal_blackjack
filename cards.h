#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string suit(int i) {
	if (i == 0) return "spades";
	if (i == 1) return "clubs";
	if (i == 2) return "diamonds";
	if (i == 3) return "hearts";
	else {
		cout << "invalid suit\n";
		exit(1);
	}
}

class Card{
	private: 
		int face = 0;
		int suit = 0;
	public:
		//constructors
		Card(int face, int suit) {
			this->face = face;
			this->suit = suit;
		}
		//accessors
		int get_face() { return face; }
		int get_suit() { return suit; }
};

void f(Card c) {
	cout << "q\n";
}


std::ostream& operator<<(std::ostream &outs, Card c) {
	string s = to_string(c.get_face()) + ", " + suit(c.get_suit());
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

