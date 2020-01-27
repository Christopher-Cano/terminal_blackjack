#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <gtest/gtest.h>
#include "cards.h"

using namespace std;

Card c(3, 0);	//number card
Card a(1, 2);	//ace
Card k (13, 1);	//king
Card b(14, 12); //invalid card
Deck d;			//default deck
Deck s;			//shuffled deck
s.shuffle();

//testingoverloaded operators for Card
TEST(card_op, GoodTests) {
	EXPECT_EQ()
}
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
	EXPECT_NE(d.getcard(0), s.getcard(0));
}

int main(int argc, char** argv) {
	if ( argc > 1) srand(stoi(argv[1]));
	else srand(0);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	/*
	Deck d;
	cout << d.get_card(0) << endl;
	cout << d.get_card(0).get_face() << ", " << d.get_card(0).get_suit() << endl;
	*/
}
