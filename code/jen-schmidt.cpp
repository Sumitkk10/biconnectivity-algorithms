#include <bits/stdc++.h>
#include <sys/time.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m, tin[N];
bool vis[N];
vector<int> g[N], euler;
vector<pair<int, bool> > dir[N]; 

long long current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;
}

void dfs(int node, int par){
	euler.pb(node);
	//cout << node << endl;
	tin[node] = euler.size();
	vis[node] = true;
	for(auto k : g[node]){
		if(!vis[k]){
			dir[k].pb({node, 0});
			dfs(k, node);
		}
		else if(vis[k] && k != par && tin[node] > tin[k])
			dir[k].pb({node, 1});
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	long long start_time = current_time();
    
	dfs(1, 0);
	// if graph is disconnected, it is not biconnected
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			// cout << "No\n";
            long long end_time = current_time();
            double elapsed_time = (end_time - start_time) / 1000.0; // Convert to seconds

            cout << fixed << setprecision(6) << elapsed_time << endl;
			return;
		}
		vis[i] = false;
	}
	int cycles = 0, total = 0;
	for(auto k : euler){
		// traverse the non tree edges in the order of lowest dfs order.
		for(auto p : dir[k]){
			if(!p.S) continue; // tree edge
			vector<int> chain;
			chain.pb(k);
			int v = p.F;
			bool dont = false;
			if(vis[v]){
				chain.pb(v);
				dont = true;
			}
			vis[k] = true;
			while(v != k){
				if(vis[v]) break;
				chain.pb(v);
				vis[v] = true;
				bool what = 0;
				for(auto dest : dir[v]){
					if(!vis[dest.F] and dest.S == 0){
						v = dest.F;
						what = 1;
						break;
					}
				}
				if(!what)
					v = dir[v][0].F;
			}
			if(!dont)
				chain.pb(v);
			total += chain.size() - 1;
            if(chain[0] == chain[chain.size() - 1])
                ++cycles;
        }
	}
	
	bool is_biconnected = 1;
	if(total != m) // all edges should be visited in the chain decomposition
		is_biconnected = 0;
	// c1 should be the only chain in C
    is_biconnected &= (cycles == 1);
	long long end_time = current_time();
    double elapsed_time = (end_time - start_time) / 1000.0; // Convert to seconds

	cout << fixed << setprecision(6) << elapsed_time << endl;
	// cout << (is_biconnected ? "Yes\n" : "No\n");
}

int32_t main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
