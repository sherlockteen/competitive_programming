#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <iomanip>
#define nl '\n'
#define ll long long
#define vi vector<int>


using namespace std;

const int maxn = 1000;
int g[maxn][maxn];


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
		{
			if (g[i][j] == 1) {
				cout << i+1 << ' ' << j+1 << '\n';
			}
		}
	}


	return 0;
}
