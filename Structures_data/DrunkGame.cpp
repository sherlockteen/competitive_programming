#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <functional>
#include <stack>
#include <queue>




void solve() {
	std::queue<int> player1;
	std::queue<int> player2;
	int cards = 5;

	for (int i = 0; i < cards; i++)
	{
		int x; std::cin >> x;
		player1.push(x);
	}

	for (int i = 0; i < cards; i++)
	{
		int x; std::cin >> x;
		player2.push(x);
	}
	
	int moves = 0;

	while (moves <= 1e6 && !player1.empty() && !player2.empty()) {
		int cardPlayer1 = player1.front();
		player1.pop();

		int cardPlayer2 = player2.front();
		player2.pop();

		if (cardPlayer1 == 0 && cardPlayer2 == 9) {
			player1.push(cardPlayer1);
			player1.push(cardPlayer2);
		}
		else if (cardPlayer1 == 9 && cardPlayer2 == 0) {
			player2.push(cardPlayer1);
			player2.push(cardPlayer2);
		}
		else if (cardPlayer2 >= cardPlayer1) {
			player2.push(cardPlayer1);
			player2.push(cardPlayer2);
		}
		else {
			player1.push(cardPlayer1);
			player1.push(cardPlayer2);
		}
		moves++;
	}

	if (player1.empty()) {
		std::cout << "second " << moves;
	}
	else if (player2.empty()) {
		std::cout << "first " << moves;
	}
	else {
		std::cout << "botva";
	}


}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

	int tt = 1;
	//std::cin >> tt;
	while (tt-- > 0) {
		solve();
	}



	return 0;
}