#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
std::vector<T> merge(std::vector<T> a, std::vector<T> b) {
	std::vector<T> res;
	int i = 0;
	int j = 0;

	while (i < a.size() && j < b.size()) {
		if (a[i] <= b[j]) {
			res.push_back(a[i++]);
		}
		else {
			res.push_back(b[j++]);
		}
	}

	while (i < a.size()) {
		res.push_back(a[i++]);
	}
	while (j < b.size()) {
		res.push_back(b[j++]);
	}

	return res;

}

template <typename T>
std::vector<T> msort(std::vector<T> a) {
	if (a.size() == 1) {
		return a;
	}
	size_t k = a.size() / 2;
	return merge(
		msort(std::vector<T>(a.begin(), a.begin() + k)),
		msort(std::vector<T>(a.begin() + k, a.end())));
}


void solve() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	arr = msort(arr);

	for (auto& el : arr)
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