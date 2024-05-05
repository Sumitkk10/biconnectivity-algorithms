#include <bits/stdc++.h>
#include <sys/time.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long
#define float long double
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pb emplace_back
#define mp make_pair
#define unique(v) (v).erase(unique((v).begin(), (v).end()), (v).end()) // creates a vector containing unique elements in sorted order (sort the vector before using to erase all duplicates) ONLY DELETES CONSECUTIVE same elements
#define sz(x) (int)((x).size())
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);

#define sp " "
#define endl '\n'

int count_bccs = 0;
int V, E;
vector<int> *adj;
vector<pair<int, int>> edges;

bool visited[1000005];
int low[1000005], discovery[1000005], cnt = 1;

long long current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;
}

bool dfs(int node, int par){
    visited[node] = true;
    discovery[node] = cnt++;
    int child = 0;
    low[node] = discovery[node];
    bool ans = 1;
    for(auto k : adj[node]){
        if(!visited[k]){
            ans &= dfs(k, node);
            low[node] = min(low[node], low[k]);
            ++child;
            if(low[k] >= discovery[node] && par != -1)
                return false;
        }
        else if(k != par)
            low[node] = min(low[node], discovery[k]);
        
    }
    if(child > 1 && par == -1)
        return false;
    return ans;
}

void solve(int test_case_no)
{
    int n, m;
    cin >> n >> m;
    V = n;
    adj = new vector<int>[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long start_time = current_time();
    bool ok = dfs(0, -1);
    for (int i = 0; i < n; i++){
        if (!visited[i])
            ok = false;
    }
    
    long long end_time = current_time();
    double elapsed_time = (end_time - start_time) / 1000.0; // Convert to seconds

	cout << fixed << setprecision(6) << elapsed_time << endl;
    // cout << (ok ? "Yes\n" : "No\n");
}

signed main()
{
    fast;
    int test_cases = 1;
    // cin >> test_cases;
    for (int test_case_ = 0; test_case_ < test_cases; test_case_++)
    {
        solve(test_case_ + 1);
    }
    return 0;
}
