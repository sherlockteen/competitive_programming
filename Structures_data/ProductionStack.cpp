#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


// Определение пользовательского исключения для пустого стека
class StackEmptyError : public std::runtime_error {
public:
	// Конструктор исключения, принимает необязательное сообщение об ошибке
	explicit StackEmptyError(const std::string& msg = "error") :
		std::runtime_error(msg) {}
};


template <typename T>
class Stack {
private:
	std::vector<T> data;
	size_t ptr;

public:
	// Конструктор стека, инициализирует ptr в 0
	Stack() : ptr(0) {}

	// Добавление элемента в стек
	void push(const T& x) {
		data.push_back(x); // Добавляем элемент в конец вектора
		ptr++; // Увеличиваем индекс вершины
		std::cout << "ok" << '\n';
	}

	// Извлечение элемента из стека
	void pop() {
		if (data.empty()) { // Проверка на пустой стек
			throw StackEmptyError(); // Выбрасываем исключение, если стек пуст
		}
		else {
			std::cout << data.back() << '\n';
			data.pop_back();
			ptr--; // Уменьшаем индекс вершины
		}
	}

	// Проверка на пустой стек
	bool empty() {
		return data.empty(); // Возвращаем true, если вектор пуст
	}

	// Возвращает верхушку стека
	T back() const {
		if (data.empty()) { // Проверка на пустой стек
			throw StackEmptyError(); // Выбрасываем исключение, если стек пуст
		}
		else {
			return data.back(); // Возвращаем последний элемент вектора
		}
	}

	size_t size() {
		return data.size();
	}

	void clear() {
		ptr = 0;
		std::cout << "ok" << '\n';
	}

};


void solve() {
	Stack<int> myStack;

	std::string cnt_input;
	std::cin >> cnt_input;

	while (true) {

		if (cnt_input == "push") {
			int x;
			std::cin >> x;
			myStack.push(x);
		}
		else if (cnt_input == "pop") {
			try {
				myStack.pop();
			}
			catch (const StackEmptyError& e) {
				std::cerr << e.what() << '\n';
			}

		}
		else if (cnt_input == "back") {
			try {
				std::cout << myStack.back() << '\n';
			}
			catch (const StackEmptyError& e) {
				std::cerr << e.what() << '\n';
			}
		}
		else if (cnt_input == "size") {
			std::cout << myStack.size() << '\n';
		}
		else if (cnt_input == "clear") {
			myStack.clear();
		}
		else if (cnt_input == "exit") {
			std::cout << "bye" << '\n';
			break;
		}

		std::cin >> cnt_input;
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