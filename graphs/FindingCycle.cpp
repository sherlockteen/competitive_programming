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
vi cycle;
int color[100001];
int stopv = -1;

bool findcycle = false;

void dfs(int v) {
    used[v] = true;
    color[v] = 1;
    for (auto to : g[v]) 
    {
        if (color[to] == 1 && !findcycle) {
            stopv = to;
            findcycle = true;
        }
        if (!used[to] && !findcycle) {
            dfs(to);
        }
    }
    if (findcycle) {
        if (stopv != -1) {
            cycle.PB(v);
        }
        if (v == stopv) {
            stopv = -1;
        }
    }

    color[v] = 2;

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

    }


    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }

    if (findcycle) {
        cout << "YES" << '\n';
        reverse(cycle.begin(), cycle.end());
        for (int i = 0; i < cycle.size(); ++i)
        {
            cout << cycle[i] + 1 << ' ';
        }
    }
    else {
        cout << "NO";

    }


    return 0;
}


