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

const ll MOD = 1e7;
const ll INF = 2e9;
const ll maxn = 1e7 + 1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n, s;
    cin >> n >> s;
    vi a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vi m(s + 1, 0), c(s + 1, 0);
    m[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = s; j >= 0; j--) {
            if (j + a[i] > s) continue;
            if (m[j] == 0) continue; // мы не сможем набратьь вес j + a[i]
            m[j + a[i]] = 1;
            c[j + a[i]] = max(c[static_cast<std::vector<int, std::allocator<int>>::size_type>(j) + a[i]], c[j] + b[i]); // испугался?
        }
    }

    int ans = 0;
    for (int i = 0; i <= s; i++) {
        ans = max(ans, c[i]);
    }

    cout << ans;
    

    return 0;
}
