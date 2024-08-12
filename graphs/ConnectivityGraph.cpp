#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define EPS 1e-9
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
const int INF = 2e9;


int maxn = 100001;
vvi g(maxn);
bool used[100001];
int ans[100001];
int cur_comp = 0;

void dfs(int v) {
    used[v] = true;
    ans[v] = cur_comp;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }

}

int n, m;



int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].PB(v);
        g[v].PB(u);

    }


    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
            cur_comp++;
        }
    }

    if (cur_comp == 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}


