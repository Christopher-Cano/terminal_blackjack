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
				return "invalid suit (" + to_string(i) + ")";
			}
		}

	public:
		//constructors
		Card(int face, int suit) {
			this->face = face;
			this->suit = suit;
		}
		//accessors
		int get_face() { 
			if (face <= 0 || face > 13) {
				cout << "invalid face (" << face << ')' << endl;
				return -1;
			}
			return face; 
		}
	
		string face_string() {
			if (face <= 0 || face > 13) {
				cout << "invalid face (" << face << ')' << endl;
				return "invalid suit (" + to_string(face) + ")";
			} else if (face == 1) { return "ace"; }
			else if (face == 11) { return "jack"; }
			else if (face == 12) { return "queen"; }
			else if (face == 13) { return "king"; }
			else return to_string(face);
		}

		
		string get_suit() { return suit_string(suit); }
};


std::ostream& operator<<(std::ostream &outs, Card c) {
	string s = to_string(c.get_face()) + ", " + c.get_suit();
	outs << s;
	return outs;
}

bool operator==(Card c, Card d) {
	if (c.get_suit() == d.get_suit() && c.get_face() == d.get_face()) return true;
	return false;
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
		//other
		void shuffle() {
			random_shuffle (vec.begin(), vec.end());
		}

};

