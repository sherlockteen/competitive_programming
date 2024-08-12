#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>


void solve() {
	std::stack<char> st;
	bool flag = true;
	std::string seq;
	getline(std::cin, seq);
	char top;

	for (char c : seq)
	{
		if (c == '(' || c == '[' || c == '{') {
			st.push(c);
		}
		else {
			if (st.empty()) {
				flag = false;
				std::cout << "no";
				exit(0);
			}
			top = st.top();
			if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
				flag = false;
				std::cout << "no";
				exit(0);
			}
				st.pop();
		}
	}

	if (flag && st.empty()) {
		std::cout << "yes";
	}
	else {
		std::cout << "no";
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