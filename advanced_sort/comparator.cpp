#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(int& x, int& y) {
	return abs(x) < abs(y); // функция компаратор
}

void solve() {
	std::vector<int> a = { -4, 2, 6, -3, -1 };

	std::sort(a.begin(), a.end(), cmp);

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