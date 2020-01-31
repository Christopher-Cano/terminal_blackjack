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
        //mutators
        Card deal() {
            Card c = this->vec.back();//deal from the back for speed
            return c;
        }
        int size() { return vec.size(); }
		void shuffle() {
            random_shuffle(vec.begin(), vec.end());
        }

};

//TODO: complete hand class
class Hand {
	private: 
		vector<Card> vec;
};

//big thing
