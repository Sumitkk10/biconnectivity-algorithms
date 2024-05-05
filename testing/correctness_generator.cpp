// This file is used to generate random testcase.
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int genNum(int l, int r) {
    return l + rand() % (r - l + 1);
}

void genGraph(int n, int m) {
    m = min(m, (n * (n - 1)) / 2);
    cout << n << ' ' << m << endl;
    map<pair<int, int>, bool> done;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        while (true) {
            int x = genNum(1, n);
            int y = genNum(1, n);
            if (x == y)continue;
            if (!done[ {x, y}] and !done[ {y, x}]) {
                edges.push_back({x, y});
                done[ {x, y}] = 1;
                done[ {y, x}] = 1;
                break;
            }
        }
    }
    for (auto x : edges)
        cout << x.first << ' ' << x.second << endl;
    return ;
}


int32_t main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    int n = genNum(1, 100), m = genNum(n, (n* (n - 1))/2);
    genGraph(n, m);
    return 0;
}
