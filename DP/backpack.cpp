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

    int n, s;
    cin >> s >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(s + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = s; j >= 0; j--) {
            if (dp[j] == 0) continue;
            if (j + a[i] > s) continue;
            dp[j + a[i]] = 1;
        }
    }

    for (int i = s; i >= 0; i--) {
        if (dp[i]) {
            cout << i;
            break;
        }
    }

    return 0;

    

    return 0;
}
