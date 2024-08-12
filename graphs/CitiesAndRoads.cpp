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

const int maxn = 10001;
int g[maxn][maxn];


int main() {
	int n;
	cin >> n;

	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			cnt += g[i][j];
		}
	}

	cout << cnt;


	

	return 0;
}
