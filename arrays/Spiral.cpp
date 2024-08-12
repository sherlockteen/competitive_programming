#include <iostream>


int main() {
	int n;
	std::cin >> n;

	int arr[n][n]= {0};
	int counter = 1;

	for (int border = 0; border < n; border++) {

		for (int i = 0 + border; i < n - border; i++) {
			arr[0 + border][i] = counter++;

		}
		counter--;

		for (int i = 0 + border; i < n - border; i++) {
			arr[i][n - 1 - border] = counter++;

		}
		counter--;

		for (int i = n - 1 - border; i >= 0 + border; i--) {
			arr[n - 1 - border][i] = counter++;

		}
		counter--;
		
		for (int i = n - 1 - border; i > 0 + border; i--) {
			arr[i][0 + border] = counter++;


		}

	}


	// print
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << '\n';

	}




	return 0;
}
