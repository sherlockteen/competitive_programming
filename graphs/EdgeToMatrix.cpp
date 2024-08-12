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
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v1, v2; 
		cin >> v1 >> v2;
		g[v1][v2] = 1;
		g[v2][v1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
		{
			cout << g[i][j] << ' ';

		}
		cout << '\n';
	}

	return 0;
}
