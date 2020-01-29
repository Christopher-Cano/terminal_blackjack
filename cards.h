#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


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
		
		//will be used when displaying card to end user
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
		//this is currently unused
		int get_suit_int() { return suit; }

};
//enables cout << Card
std::ostream& operator<<(std::ostream &outs, Card c) {
	string s = c.face_string() + " of " + c.get_suit();
	outs << s;
	return outs;
}
//the Card == and != operators are mostly for the tests
bool operator==(Card c, Card d) {
	if (c.get_suit() == d.get_suit() && c.get_face() == d.get_face()) return true;
	return false;
}
bool operator!=(Card c, Card d) {
	if (c.get_suit() == d.get_suit() && c.get_face() == d.get_face()) return false;
	return true;
}

//TODO: add deal function
//TODO: add deck size accessor


//TODO: complete hand class

