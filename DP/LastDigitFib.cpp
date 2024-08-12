#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map> 
#include <cassert>
#define ll long long
#define PB push_back
#define EPS 1e-9
#define nl '\n'
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<int> vi;
typedef vector<string> vs;

const ll INF = 2e9;
const ll maxn = 1e7;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    n += 1;


    vector<ll> f(n + 2);
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        (f[i] = f[i - 1] + f[i - 2]) %= 10;
    }
    cout << f[n] % 10;

    return 0;
}
