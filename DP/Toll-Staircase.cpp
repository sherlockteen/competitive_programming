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

const ll MOD = 1e7 + 7;
const ll INF = 2e9;
const ll maxn = 1e7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<ll> a(n + 1);
    vector<ll> dp(n + 1, 0);

    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 0;
    dp[1] = a[1];

    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + a[i];
    }
    cout << dp[n];

    return 0;
}
