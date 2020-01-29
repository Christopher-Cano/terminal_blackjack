#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
#include "cards.h"

using namespace std;

Card c(3, 0);	//number card
Card a(1, 2);	//ace
Card k (13, 1);	//king
Card b(14, 12); //invalid card
Card deal_test(-1, -1);	//used for testing deck.deal()
Deck d;			//default deck
Deck s;			//shuffled deck (executed in main)

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
//enable these when their respective functions have been created
/*
TEST(DeckSize, GoodTests) {
	EXPECT_EQ(d.size(), 52);
}
TEST(DeckDeal, GoodTests) {
	EXPECT_EQ(s.deal(), deal_test);
	EXPECT_NE(s.get_card, deal_test);

}
*/

int main(int argc, char** argv) {
	s.shuffle();
	deal_test = s.get_card(12);
	if ( argc > 1) srand(stoi(argv[1]));
	else srand(0);
	Card z(1, 2);
	cout << z << endl;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	/*
	Deck d;
	cout << d.get_card(0) << endl;
	cout << d.get_card(0).get_face() << ", " << d.get_card(0).get_suit() << endl;
	*/
}
