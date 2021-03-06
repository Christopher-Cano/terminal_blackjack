#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
#include "cards.h"
#include "deck.h"

using namespace std;

Card c(3, 0);	//number card
Card a(1, 2);	//ace
Card k (13, 1);	//king
Card b(14, 12); //invalid card
Card deal_test(-1, -1);	//used for testing deck.deal()
Deck d;			//default deck
Deck s;			//shuffled deck (executed in main)

int place_bet(
//TODO: test overloaded operators for Card
/*
TEST(card_op, GoodTests) {
	EXPECT_EQ()
}
*/
//tests related to card suits
TEST(suit, GoodTests) {
	EXPECT_EQ(c.get_suit(), "spades");
}

TEST(suit, BadTests) {
	EXPECT_EQ(b.get_suit(), "invalid suit (12)");
}

//tests related to card face
TEST(face, GoodTests) {
	EXPECT_EQ(c.get_face(), 3);
	EXPECT_EQ(a.face_string(), "ace");
	EXPECT_EQ(k.face_string(), "king");
}

TEST(face, BadTests) {
	EXPECT_EQ(b.get_face(), -1);
}

//tests related to Deck
TEST(DeckGetCard, GoodTests) {
	EXPECT_EQ(d.get_card(2), a);
	EXPECT_EQ(d.get_card(49), k);
	EXPECT_EQ(d.get_card(3 * 3 - 1), c);
}

TEST(DeckShuffle, GoodTests) {
	EXPECT_NE(d.get_card(0), s.get_card(0));
}
TEST(DeckSize, GoodTests) {
	EXPECT_EQ(d.size(), 52);
}
TEST(DeckDeal, GoodTests) {
	EXPECT_EQ(s.deal(), deal_test);
	EXPECT_NE(s.get_card(0), deal_test);

}

int main(int argc, char** argv) {
	s.shuffle();
	deal_test = s.get_card(s.size() - 1);
	if ( argc > 1) srand(stoi(argv[1]));
	else srand(0);
	Card z(1, 2);
	cout << z << endl;
	testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
	int users = 0;
	//ask for number of players
	cout << "ENTER AMOUNT OF PLAYERS(1-6)\n";
	cin >> users;
	//vet input
	if(!cin or users < 1 or users > 6){
		cout << "BAD INPUT!\n";
		exit(1);
	}
	//start it up
	cout << "ENTER THE GAME!\n";
	cout << "==================================================================\n";
	//make a vector the size of the amount of users numbers 0-total-1
	vector<int> players;
	for(int i = 0; i < users; i++){
		players.push_back(i);
	}
	vector<int> bank;
	for(int i = 0; i < players.size(); i++){
		bank.push_back(1000);
	}
	cout << "PLACE INITIAL BET value from 2-500\n";
	cout << players.size();
	/*
	Deck d;
	cout << d.get_card(0) << endl;
	cout << d.get_card(0).get_face() << ", " << d.get_card(0).get_suit() << endl;
	*/
}
