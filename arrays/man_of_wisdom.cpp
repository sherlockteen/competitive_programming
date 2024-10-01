#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>


void solve() {
	int n, m, x;
	std::cin >> n;
	std::cin >> m;
	std::vector<std::vector<int>> t(n, std::vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> t[i][j];
		}
	}

	std::cin >> x;
	std::vector<std::pair<int, int>> path;
	for (int i = 0; i < x; i++)
	{
		int x, y;
		std::cin >> x >> y;
		x--; y--;
		path.push_back({ x, y });
	}

	int sum = 0;
	for (auto& el : path) {
		sum += t[el.first][el.second];
		t[el.first][el.second] = 0;
	}

	std::cout << sum;
}

int32_t main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

	int tt = 1;
	//std::cin >> tt;
	while (tt-- > 0) {
		solve();
	}

	return 0;
}

//Task:
/*
Мудрец ходит по комнате размером n×m клеток. В каждой клетке комнаты лежит заданное количество золота. 
Проходя по клетке, мудрец забирает всё золото с неё. 
Зная план комнаты и маршрут мудреца, посчитайте, сколько золота он собрал. 
В задаче не гарантируется, что мудрец не проходил по одной и той же клетке более одного раза.


Выведите количество килограммов золота, которое собрал мудрец.
*/
