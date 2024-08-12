#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <functional>
#include <stack>
#include <map>


void solve() {
	std::string expression;
	std::getline(std::cin, expression);

	std::istringstream iss(expression);
	std::string token;
	std::stack<int> operands;
	std::remove_if(expression.begin(), expression.end(), isspace);

	while (iss >> token) {
		if (std::isdigit(token[0])) {
			operands.push(std::stoi(token));
		}
		else {
			int operand2 = operands.top();
			operands.pop();
			int operand1 = operands.top();
			operands.pop();

			switch (token[0])
			{
			case '+': 
				operands.push(operand1 + operand2);
				break;
			case '-': 
				operands.push(operand1 - operand2);
				break;
			case '*':
				operands.push(operand1 * operand2);
				break;
			}
			
		}
	}

	std::cout << operands.top();
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