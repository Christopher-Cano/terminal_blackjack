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

//tests related to card suits
TEST(suit, GoodTests) {
	EXPECT_EQ(c.get_suit(), "spades");
}

TEST(suit, BadTests) {
	EXPECT_EQ(b.get_suit(), "invalid suit (12)\n");
}

//tests related to card face
TEST(face, GoodTests) {
	EXPECT_EQ(c.get_face(), 3);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	/*
	Deck d;
	cout << d.get_card(0) << endl;
	cout << d.get_card(0).get_face() << ", " << d.get_card(0).get_suit() << endl;
	*/
}
