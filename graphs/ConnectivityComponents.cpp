#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define nl '\n'
#define ll long long
#define vi vector<int>

using namespace std;

const int maxn = 100000;
vector<vector<int>> g(maxn);
vector<int> component(maxn, 0);
vector<vector<int>> vertex_comp(maxn);
bool used[maxn];
int n, m;

void dfs(int v, int component_id) {
    used[v] = true;
    component[v] = component_id;
    vertex_comp[component_id].push_back(v);
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u, component_id);
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    int v1, v2;

    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--; v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int component_size = 0;

    for (int v = 0; v < n; v++) {
        if (!used[v]) {
            dfs(v, ++component_size);
        }
    }

    cout << component_size << endl;
    vector<int> arr_comp_size(component_size + 1, 0);

    for (int i = 0; i < n; i++) {
        arr_comp_size[component[i]]++;
    }

    for (int i = 1; i <= component_size; i++) {
        cout << arr_comp_size[i] << endl;
        for (int v : vertex_comp[i]) {
            cout << v + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}