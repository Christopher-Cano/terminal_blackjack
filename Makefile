a.out: main.cc cards.h deck.h
	g++ main.cc -lgtest -pthread -DFOO -Wall -Wextra -Werror -std=c++17 -Wno-unused-variable -Wno-unused-parameter -o a.out

clean:
	rm a.out

