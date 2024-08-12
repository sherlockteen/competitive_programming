#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define PB push_back
#define EPS 1e-9
#define nl '\n'
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<int> vi;
typedef vector<string> vs;

const ll INF = 2e9;
const ll maxn = 1e6;
ll min1 = LLONG_MAX;

struct Stack {
    vi a;
    int ptr;

    Stack() {
        a.resize(maxn);
        ptr = 0;
    }

    void push(int x) {
        a[ptr++] = x;
        cout << "ok" << nl;
    }
    void push_min(int x) {
        a[ptr++] = x;
    }

    void back() {
        if (ptr != 0) {
            cout << a[ptr - 1] << nl;

        }
        else {
            cout << "error" << nl;
        }
    }

    void pop() {
        if (ptr == 0) {
            cout << "error" << nl;
        }
        else {
            cout << a[ptr - 1] << nl;
            ptr--;
        }

    }

    int size() {
        return ptr;
    }

    void clear() {
        ptr = 0;
        cout << "ok" << nl;
    }

    int getMin() {
        if (ptr == 0) {
            cout << "error" << endl;
            return -1;
        }
        else {
            int minVal = a[0];
            for (int i = 1; i < ptr; i++) {
                minVal = min(minVal, a[i]);
            }
            cout << minVal << endl;
            return minVal;
        }
    }

};


int main() {
    int n;
    cin >> n;

    Stack st;

    for (int i = 0; i < n; i++) {
        string inputer;
        cin >> inputer;

        if (inputer == "push") {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (inputer == "pop") {
            st.pop();
        }
        else if (inputer == "back") {
            st.back();
        }
        else if (inputer == "size") {
            cout << st.size() << endl;
        }
        else if (inputer == "clear") {
            st.clear();
        }
        else if (inputer == "min") {
            st.getMin();
        }
    }

    return 0;
}
