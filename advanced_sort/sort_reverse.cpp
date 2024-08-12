#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(int& x, int& y) {
	return abs(x) < abs(y); // ф-ия компаратор
}

void solve() {
	std::vector<int> a = { 17,23,14,8,19 };

	std::sort(a.rbegin(), a.rend());

	for (auto& el : a)
	{
		std::cout << el << ' ';
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