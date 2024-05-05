#include <bits/stdc++.h>
using namespace std;
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


int main(int argc, char** argv) {
    if(argc != 3) {
        cout << "Usage: " << argv[0] << " <n> <m>\n";
        return 1;
    }
    
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    
    srand(chrono::steady_clock::now().time_since_epoch().count());
    genGraph(n, m);
    	
    return 0;
}

