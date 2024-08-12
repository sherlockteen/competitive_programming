#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define pb push_back
#define fi first 
#define se second
#define vi vector<int> 
#define vl vector<ll> 
#define vvi vector<vi> 
#define vvl vector<vl> 
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vii vector<pii> 
#define vll vector<pll> 
#define all(x) begin(x), end(x)

const int INF = 2e9;
const ll INFL = 9e18;
const double EPS = 1e-7;
const int MOD = 1e6 + 3;
const int maxn = 1e7 + 1;

ull binpow_rec(ull a, ull b, ull m) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a % m;

	if (b & 1) 
		return (binpow_rec((a * a) % m, b >> 1, m) * a) % m;
	else
		return binpow_rec((a * a) % m, b >> 1, m) % m;

}



ull binpow(ull a, ull b, ull m) {
	ull ans = 1;
	while (b > 0) {
		if (b & 1)
			ans = (ans * a) % m;
		a = (a * a) % m;
		b = b >> 1; // тоже самое что поделить на 2
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	ull n, m;
	cin >> n >> m;
	
	ull ans = binpow(n, n, m) % m;
	
	cout << ans % m;
	


	return 0;
}