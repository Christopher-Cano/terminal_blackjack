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


string operator<<(const Card c, int i) {
	string s = to_string(c.get_face()) + ", " + suit[c.get_suit()];
	return s;
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

int main() {
	Deck d;
	cout << d.get_card(0).get_face() << ", " << d.get_card(0).get_suit() << endl;
	//cout << d.get_card(0) << endl;
}
