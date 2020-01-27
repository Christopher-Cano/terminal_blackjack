a.out: main.cc cards.h
	g++ main.cc cards.h -lgtest -pthread -DFOO -Wall -Wextra -Werror -std=c++17 -Wno-unused-variable -Wno-unused-parameter -o a.out

clean:
	rm a.out

