#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include "cards.h"

using namespace std;

int main() {
	Deck d;
	cout << d.get_card(0) << endl;
	cout << d.get_card(0).get_face() << ", " << d.get_card(0).get_suit() << endl;
	//cout << d.get_card(0) << endl;
}
